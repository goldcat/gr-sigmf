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
#include <sigmf/sigmf.h>

namespace gr {
  namespace sigmf {

    sigmf::sigmf (const std::string &metadata_filename)
    {
      d_doc = new rapidjson::Document();
      set_filenames (metadata_filename);
    }

    sigmf::~sigmf ()
    {
    }

    void
    sigmf::init_object_iterators() {
      d_sigmf_itr_begin = d_doc->MemberBegin();
      d_sigmf_itr_end = d_doc->MemberEnd();

      d_global_itr_begin = (*d_doc)["global"].GetObject().MemberBegin();
      d_global_itr_end = (*d_doc)["global"].GetObject().MemberEnd();

      d_capture_itr_begin = (*d_doc)["capture"].GetArray().Begin();
      d_capture_itr_end = (*d_doc)["capture"].GetArray().End();

      d_annotation_itr_begin = (*d_doc)["annotation"].GetArray().Begin();
      d_annotation_itr_end = (*d_doc)["annotation"].GetArray().End();
    }

    void
    sigmf::set_sigmf_itr_begin (
	const rapidjson::Value::MemberIterator& sigmfitrbegin)
    {
      d_sigmf_itr_begin = sigmfitrbegin;
    }

    void
    sigmf::set_sigmf_itr_end (
	const rapidjson::Value::MemberIterator& sigmfitrend)
    {
      d_sigmf_itr_end = sigmfitrend;
    }

    void
    sigmf::set_capture_itr_begin (
	const rapidjson::Value::ValueIterator& captureitrbegin)
    {
      d_capture_itr_begin = captureitrbegin;
    }

    void
    sigmf::set_capture_itr_end (
	const rapidjson::Value::ValueIterator& captureitrend)
    {
      d_capture_itr_end = captureitrend;
    }

    void
    sigmf::set_annotation_itr_begin (
	const rapidjson::Value::ValueIterator& annotationitrbegin)
    {
      d_annotation_itr_begin = annotationitrbegin;
    }

    void
    sigmf::set_annotation_itr_end (
	const rapidjson::Value::ValueIterator& annotationitrend)
    {
      d_annotation_itr_end = annotationitrend;
    }

    void
    sigmf::set_global_itr_begin (
	const rapidjson::Value::MemberIterator& globalitrbegin)
    {
      d_global_itr_begin = globalitrbegin;
    }

    void
    sigmf::set_global_itr_end (
	const rapidjson::Value::MemberIterator& globalitrend)
    {
      d_global_itr_end = globalitrend;
    }

    void
    sigmf::set_filenames (const std::string& metadata_filename)
    {
      d_metadata_filename = metadata_filename;
      d_dataset_filename = metadata_filename;

      std::string dataset_suffix = "sigmf-data";
      size_t prefix_idx = metadata_filename.find_last_of (".") + 1;

      d_dataset_filename.replace (prefix_idx,
				  dataset_suffix.length (),
				  dataset_suffix);
    }

  } /* namespace sigmf */
} /* namespace gr */

