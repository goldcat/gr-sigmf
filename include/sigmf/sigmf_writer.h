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

#ifndef INCLUDED_SIGMF_SIGMF_WRITER_H
#define INCLUDED_SIGMF_SIGMF_WRITER_H

#include <sigmf/api.h>
#include <vector>
#include <sigmf/sigmf.h>
#include <sigmf/global.h>
#include <sigmf/capture.h>
#include <sigmf/annotation.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/writer.h>

namespace gr {
  namespace sigmf {

    /*!
     * \brief <+description+>
     *
     */
    class SIGMF_API sigmf_writer : public sigmf
    {
      public:
	sigmf_writer (const std::string &metadata_filename);

	~sigmf_writer ();

	void
	add_global_object (global obj);

	void
	add_capture_array (std::vector<capture> vec);

	void
	add_annotation_array (std::vector<annotation> vec);

      private:
	FILE* d_fp;
	rapidjson::FileWriteStream *d_fws;
	rapidjson::Writer<rapidjson::FileWriteStream> *d_writer;

	void
	add_capture_object (capture obj);

	void
	add_annotation_object (annotation obj);
    };

  } // namespace sigmf
} // namespace gr

#endif /* INCLUDED_SIGMF_SIGMF_WRITER_H */

