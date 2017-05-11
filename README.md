

# gr-sigmf: GNU Radio OOT module for SigMF

## Introduction
This GNU Radio Out-of-Tree module aims to provide support on the Signal Metafile Format specification ( [SigMF](https://github.com/gnuradio/SigMF)). More specifically, the module's main contributions include: 

- JSON C++ manipulation API
- SigMF source block
- SigMF sink block
- Converters from/to SigMF specification
- Stand-alone QT GUI

## Installation

To install gr-sigmf the following dependencies are required:

- [GNU Radio](https://github.com/gnuradio/gnuradio)

Install by the following shell commands:

```
git clone git@github.com:ctriant/gr-sigmf.git
cd gr-sigmf
mkdir build
cd build
cmake ..
make -j4
sudo make install

```


## Google Summer of Code 

This GNU Radio Out-of-Tree module is implemented for the needs of Google Summer of Code (GSoC) 2017. For more information regarding the project please read the full project proposal [here](https://github.com/ctriant/GSoC17-Proposal/blob/master/gsoc17_proposal.pdf).


## License
This software is Copyright © 2017 Free Software Foundation, Inc. and part of GNU Radio. It is free software, and is released under the [GPLv3](https://www.gnu.org/licenses/gpl-3.0.en.html) License.


## Contact
Maintainer of this module:

**Kostis Triantafyllakis**
ctriant[at]csd.uoc.gr

Mentors:

**Bastian Bloessl**
bloessl[at]ccs-labs.org

**Sebastian Müller**
gsenpo[at]gmail.com

To get more info and news regarding the project's progress, please visit the  [blog](http://ixion.csd.uoc.gr/ctriant/).

Also please consider the GNU Radio [mailing list](http://gnuradio.org/redmine/projects/gnuradio/wiki/MailingLists).
