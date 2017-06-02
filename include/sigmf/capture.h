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

#ifndef INCLUDED_SIGMF_CAPTURE_H
#define INCLUDED_SIGMF_CAPTURE_H

#include <sigmf/api.h>

namespace gr {
  namespace sigmf {

    /*!
     * \brief Class that represents the capture object of the SigMF
     * specification.
     *
     */
    class SIGMF_API capture
    {
      public:
	capture ();
	capture (size_t sample_start);
	~capture ();

	const std::string&
	get_datetime () const;

	void
	set_datetime (const std::string& datetime);

	double
	get_frequency () const;

	void
	set_frequency (double frequency);

	size_t
	get_sample_start () const;

	void
	set_sample_start (size_t samplestart);

      private:
	size_t d_sample_start;

	double d_frequency;

	std::string d_datetime;

    };

  } // namespace sigmf
} // namespace gr

#endif /* INCLUDED_SIGMF_CAPTURE_H */

