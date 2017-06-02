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

#ifndef INCLUDED_SIGMF_GLOBAL_H
#define INCLUDED_SIGMF_GLOBAL_H

#include <sigmf/api.h>

namespace gr {
  namespace sigmf {

    /*!
     * \brief Class that represents the global object of the SigMF
     * specification.
     */
    class SIGMF_API global
    {
      public:
	global ();
	global (std::string datatype, std::string version);
	~global ();

	const std::string&
	get_author () const;

	void
	set_author (const std::string& author);

	const std::string&
	get_datatype () const;

	void
	set_datatype (const std::string& datatype);

	const std::string&
	get_description () const;
	void
	set_description (const std::string& description);

	const std::string&
	get_hw () const;

	void
	set_hw (const std::string& hw);

	const std::string&
	get_license () const;

	void
	set_license (const std::string& license);

	size_t
	get_offset () const;

	void
	set_offset (size_t offset);

	double
	get_sample_rate () const;

	void
	set_sample_rate (double samplerate);

	const std::string&
	get_sha512 () const;

	void
	set_sha512 (const std::string& sha512);

	const std::string&
	get_version () const;

	void
	set_version (const std::string& version);

      private:

	std::string d_datatype;
	std::string d_version;
	std::string d_sha512;
	std::string d_description;
	std::string d_author;
	std::string d_license;
	std::string d_hw;

	double d_sample_rate;

	size_t d_offset;

    };

  } // namespace sigmf
} // namespace gr

#endif /* INCLUDED_SIGMF_GLOBAL_H */

