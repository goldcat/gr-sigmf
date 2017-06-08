/* -*- c++ -*- */
/*
 * Copyright 2017 Kostis Triantafyllakis.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include <sigmf/sigmf_writer.h>
#include <rapidjson/pointer.h>
#include <iostream>

namespace gr {
  namespace sigmf {

    sigmf_writer::sigmf_writer (const std::string &metadata_filename,
				sigmfType type) :
	    sigmf (metadata_filename, type)
    {
      d_fp = fopen (metadata_filename.c_str (), "r+");
      d_fws = new rapidjson::FileWriteStream (d_fp, d_buf,
					      sizeof(d_buf));
      d_writer = new rapidjson::PrettyWriter<
	  rapidjson::FileWriteStream> (*d_fws);
    }

    sigmf_writer::~sigmf_writer ()
    {
      fclose (d_fp);
    }

    void
    sigmf_writer::add_global_object (global obj)
    {
      d_writer->StartObject ();
      if (obj.get_datatype ().empty ()) {
	throw std::runtime_error ("sigmf_writer: datatype empty");
      }
      d_writer->Key ("datatype");
      d_writer->String (obj.get_datatype ().c_str ());

      if (obj.get_version ().empty ()) {
	throw std::runtime_error ("sigmf_writer: version empty");
      }
      d_writer->Key ("version");
      d_writer->String (obj.get_version ().c_str ());

      if (!obj.get_sha512 ().empty ()) {
	d_writer->Key ("sha512");
	d_writer->String (obj.get_sha512 ().c_str ());
      }

      if (!obj.get_description ().empty ()) {
	d_writer->Key ("description");
	d_writer->String (obj.get_description ().c_str ());
      }

      if (!obj.get_author ().empty ()) {
	d_writer->Key ("author");
	d_writer->String (obj.get_author ().c_str ());
      }

      if (!obj.get_license ().empty ()) {
	d_writer->Key ("license");
	d_writer->String (obj.get_license ().c_str ());
      }

      if (!obj.get_hw ().empty ()) {
	d_writer->Key ("hw");
	d_writer->String (obj.get_hw ().c_str ());
      }

      if (obj.get_sample_rate () != -1) {
	d_writer->Key ("sample_rate");
	d_writer->Double (obj.get_sample_rate ());
      }

      if (obj.get_offset () != -1) {
	d_writer->Key ("sample_rate");
	d_writer->Uint64 (obj.get_offset ());

      }
      d_writer->EndObject ();
    }

    void
    sigmf_writer::add_capture_object (capture obj)
    {
      d_writer->StartObject ();
      if (obj.get_sample_start () == -1) {
	throw std::runtime_error (
	    "sigmf_writer: capture sample_start empty");
      }
      d_writer->Key ("sample_start");
      d_writer->Uint64 (obj.get_sample_start ());

      if (obj.get_frequency () != -1) {
	d_writer->Key ("frequency");
	d_writer->Double (obj.get_frequency ());
      }

      if (!obj.get_datetime ().empty ()) {
	d_writer->Key ("datetime");
	d_writer->String (obj.get_datetime ().c_str ());
      }
      d_writer->EndObject ();
    }

    void
    sigmf_writer::add_capture_array (std::vector<capture> vec)
    {
      if (!vec.empty ()) {
	d_writer->StartArray ();
	for (size_t i = 0; i < vec.size (); i++) {
	  add_capture_object (vec[i]);
	}
	d_writer->EndArray ();
      }
    }

    void
    sigmf_writer::add_annotation_object (annotation obj)
    {
      d_writer->StartObject ();
      if (obj.get_sample_start () == -1) {
	throw std::runtime_error (
	    "sigmf_writer: annotation sample_start empty");
      }
      d_writer->Key ("sample_start");
      d_writer->Uint64 (obj.get_sample_start ());

      if (obj.get_sample_count () == -1) {
	throw std::runtime_error (
	    "sigmf_writer: annotation sample_count empty");
      }
      d_writer->Key ("sample_count");
      d_writer->Uint64 (obj.get_sample_count ());

      if (obj.get_freq_lower_edge () != -1) {
	d_writer->Key ("freq_lower_edge");
	d_writer->Double (obj.get_freq_lower_edge ());
      }

      if (obj.get_freq_upper_edge () != -1) {
	d_writer->Key ("freq_upper_edge");
	d_writer->Double (obj.get_freq_upper_edge ());
      }

      if (!obj.get_generator ().empty ()) {
	d_writer->Key ("generator");
	d_writer->String (obj.get_generator ().c_str ());
      }

      if (!obj.get_comment ().empty ()) {
	d_writer->Key ("comment");
	d_writer->String (obj.get_comment ().c_str ());
      }

      d_writer->EndObject ();
    }

    void
    sigmf_writer::add_annotation_array (std::vector<annotation> vec)
    {
      if (!vec.empty ()) {
	d_writer->StartArray ();
	for (size_t i = 0; i < vec.size (); i++) {
	  add_annotation_object (vec[i]);
	}
	d_writer->EndArray ();
      }
    }

    void
    sigmf_writer::append_captures (capture c, rapidjson::Document *d)
    {
      if ((*d).HasMember ("capture")) {
	rapidjson::Value *v = parse_capture (c);
	(*d)["capture"].PushBack (*v, (*d).GetAllocator ());
	(*d).Accept (*d_writer);
      }
      else {
	throw std::runtime_error (
	    "append_captures: no top-level object found");
      }
    }

    void
    sigmf_writer::append_captures (std::vector<capture> vec,
				   rapidjson::Document *d)
    {
      rapidjson::Value *v;
      if ((*d).HasMember ("capture")) {
	for (size_t s = 0; s < vec.size (); s++) {
	  v = parse_capture (vec[s]);
	  (*d)["capture"].PushBack (*v, (*d).GetAllocator ());
	}
	(*d).Accept (*d_writer);
      }
      else {
	throw std::runtime_error (
	    "append_captures: no top-level object found");
      }
    }

    void
    sigmf_writer::append_annotations (annotation a,
				      rapidjson::Document *d)
    {
      if ((*d).HasMember ("annotation")) {
	rapidjson::Value *v = parse_annotation (a);
	(*d)["annotation"].PushBack (*v, (*d).GetAllocator ());
	(*d).Accept (*d_writer);
      }
      else {
	throw std::runtime_error (
	    "append_annotation: no top-level object found");
      }
    }

    void
    sigmf_writer::append_annotations (std::vector<annotation> vec,
				      rapidjson::Document *d)
    {
      rapidjson::Value *v;
      if ((*d).HasMember ("annotation")) {
	for (size_t s = 0; s < vec.size (); s++) {
	  v = parse_annotation (vec[s]);
	  (*d)["annotation"].PushBack (*v, (*d).GetAllocator ());
	}
	(*d).Accept (*d_writer);
      }
      else {
	throw std::runtime_error (
	    "append_annotations: no top-level object found");
      }
    }

  } /* namespace sigmf */
} /* namespace gr */

