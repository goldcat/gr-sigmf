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
#include <sigmf/capture.h>

namespace gr {
  namespace sigmf {

    capture::capture ()
    {
      d_sample_start = -1;
      d_frequency = -1;
    }

    capture::capture (size_t sample_start)
    {
      d_sample_start = sample_start;
      d_frequency = -1;
    }

    capture::~capture ()
    {
    }

    const std::string&
    capture::get_datetime () const
    {
      return d_datetime;
    }

    void
    capture::set_datetime (const std::string& datetime)
    {
      d_datetime = datetime;
    }

    double
    capture::get_frequency () const
    {
      return d_frequency;
    }

    void
    capture::set_frequency (double frequency)
    {
      d_frequency = frequency;
    }

    size_t
    capture::get_sample_start () const
    {
      return d_sample_start;
    }

    void
    capture::set_sample_start (size_t samplestart)
    {
      d_sample_start = samplestart;
    }

  } /* namespace sigmf */
} /* namespace gr */

