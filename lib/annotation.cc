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
#include <sigmf/annotation.h>

namespace gr {
  namespace sigmf {

    annotation::annotation ()
    {
      d_sample_start = -1;
      d_sample_count = -1;

      d_freq_lower_edge = -1;
      d_freq_upper_edge = -1;
    }

    annotation::annotation (size_t sample_start, size_t sample_count)
    {
      d_sample_start = sample_start;
      d_sample_count = sample_count;

      d_freq_lower_edge = -1;
      d_freq_upper_edge = -1;
    }

    annotation::~annotation ()
    {
    }

    const std::string&
    annotation::get_comment () const
    {
      return d_comment;
    }

    void
    annotation::set_comment (const std::string& comment)
    {
      d_comment = comment;
    }

    double
    annotation::get_freq_lower_edge () const
    {
      return d_freq_lower_edge;
    }

    void
    annotation::set_freq_lower_edge (double freqloweredge)
    {
      d_freq_lower_edge = freqloweredge;
    }

    double
    annotation::get_freq_upper_edge () const
    {
      return d_freq_upper_edge;
    }

    void
    annotation::set_freq_upper_edge (double frequpperedge)
    {
      d_freq_upper_edge = frequpperedge;
    }

    const std::string&
    annotation::get_generator () const
    {
      return d_generator;
    }

    void
    annotation::set_generator (const std::string& generator)
    {
      d_generator = generator;
    }

    size_t
    annotation::get_sample_count () const
    {
      return d_sample_count;
    }

    void
    annotation::set_sample_count (size_t samplecount)
    {
      d_sample_count = samplecount;
    }

    size_t
    annotation::get_sample_start () const
    {
      return d_sample_start;
    }

    void
    annotation::set_sample_start (size_t samplestart)
    {
      d_sample_start = samplestart;
    }

  } /* namespace sigmf */
} /* namespace gr */

