// This file is part of the AliceVision project and is made available under
// the terms of the MPL2 license (see the COPYING.md file).

#include "aliceVision/exif/EasyExifIO.hpp"
using namespace aliceVision::exif;

#include "dependencies/cmdLine/cmdLine.h"
#include <memory>

int main(int argc, char **argv)
{
  CmdLine cmd;

  std::string sInputImage;

  cmd.add( make_option('i', sInputImage, "imafile") );

  try {
      if (argc == 1) throw std::string("Invalid command line parameter.");
      cmd.process(argc, argv);
  } catch(const std::string& s) {
      std::cerr << "Usage: " << argv[0] << ' '
      << "[-i|--imafile path] "
      << std::endl;

      std::cerr << s << std::endl;
      return EXIT_FAILURE;
  }

  std::cout << " You called : " <<std::endl
            << argv[0] << std::endl
            << "--imafile " << sInputImage << std::endl;
  
  std::unique_ptr<ExifIO> exif_io( new EasyExifIO( sInputImage ) );

  std::cout << "width : " << exif_io->getWidth() << std::endl;
  std::cout << "height : " << exif_io->getHeight() << std::endl;
  std::cout << "focal : " << exif_io->getFocal() << std::endl;
  std::cout << "brand : " << exif_io->getBrand() << std::endl;
  std::cout << "model : " << exif_io->getModel() << std::endl;
  return EXIT_SUCCESS;
}



