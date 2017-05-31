/* -*- c++ -*- */

#define SIGMF_API

%include "gnuradio.i"

//load generated python docstrings
%include "sigmf_swig_doc.i"

%{
#include "sigmf/global.h"
#include "sigmf/capture.h"
#include "sigmf/annotation.h"
#include "sigmf/sigmf.h"
#include "sigmf/sigmf_reader.h"
%}
%include "sigmf/global.h"
%include "sigmf/capture.h"
%include "sigmf/annotation.h"
%include "sigmf/sigmf.h"
%include "sigmf/sigmf_reader.h"
