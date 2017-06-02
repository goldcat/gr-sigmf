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

#ifndef INCLUDED_SIGMF_ANNOTATION_H
#define INCLUDED_SIGMF_ANNOTATION_H

#include <sigmf/api.h>

namespace gr {
  namespace sigmf {

    /*!
     * \brief Class that represents the annotation object of the SigMF
     * specification.
     *
     */
    class SIGMF_API annotation
    {
      public:
	annotation ();
	annotation (size_t sample_start, size_t sample_count);
	~annotation ();

	const std::string&
	get_comment () const;

	void
	set_comment (const std::string& comment);

	double
	get_freq_lower_edge () const;

	void
	set_freq_lower_edge (double freqloweredge);

	double
	get_freq_upper_edge () const;

	void
	set_freq_upper_edge (double frequpperedge);

	const std::string&
	get_generator () const;

	void
	set_generator (const std::string& generator);

	size_t
	get_sample_count () const;

	void
	set_sample_count (size_t samplecount);

	size_t
	get_sample_start () const;

	void
	set_sample_start (size_t samplestart);

      private:
	size_t d_sample_start;
	size_t d_sample_count;

	std::string d_generator;
	std::string d_comment;

	double d_freq_lower_edge;
	double d_freq_upper_edge;
    };

  } // namespace sigmf
} // namespace gr

#endif /* INCLUDED_SIGMF_ANNOTATION_H */

