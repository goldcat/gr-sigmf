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
#include <sigmf/global.h>

namespace gr {
  namespace sigmf {

    global::global ()
    {
      d_sample_rate = -1;
      d_offset = -1;
    }

    global::global (std::string datatype, std::string version)
    {
      d_datatype = datatype;
      d_version = version;
      d_sample_rate = -1;
      d_offset = -1;
    }

    global::~global ()
    {
    }

    const std::string&
    gr::sigmf::global::get_author () const
    {
      return d_author;
    }

    void
    gr::sigmf::global::set_author (const std::string& author)
    {
      d_author = author;
    }

    const std::string&
    gr::sigmf::global::get_datatype () const
    {
      return d_datatype;
    }

    void
    gr::sigmf::global::set_datatype (const std::string& datatype)
    {
      d_datatype = datatype;
    }

    const std::string&
    gr::sigmf::global::get_description () const
    {
      return d_description;
    }

    void
    gr::sigmf::global::set_description (
	const std::string& description)
    {
      d_description = description;
    }

    const std::string&
    gr::sigmf::global::get_hw () const
    {
      return d_hw;
    }

    void
    gr::sigmf::global::set_hw (const std::string& hw)
    {
      d_hw = hw;
    }

    const std::string&
    gr::sigmf::global::get_license () const
    {
      return d_license;
    }

    void
    gr::sigmf::global::set_license (const std::string& license)
    {
      d_license = license;
    }

    size_t
    gr::sigmf::global::get_offset () const
    {
      return d_offset;
    }

    void
    gr::sigmf::global::set_offset (size_t offset)
    {
      d_offset = offset;
    }

    double
    gr::sigmf::global::get_sample_rate () const
    {
      return d_sample_rate;
    }

    void
    gr::sigmf::global::set_sample_rate (double samplerate)
    {
      d_sample_rate = samplerate;
    }

    const std::string&
    gr::sigmf::global::get_sha512 () const
    {
      return d_sha512;
    }

    void
    gr::sigmf::global::set_sha512 (const std::string& sha512)
    {
      d_sha512 = sha512;
    }

    const std::string&
    gr::sigmf::global::get_version () const
    {
      return d_version;
    }

    void
    gr::sigmf::global::set_version (const std::string& version)
    {
      d_version = version;
    }

  } /* namespace sigmf */
} /* namespace gr */
