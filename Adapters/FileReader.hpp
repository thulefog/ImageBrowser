//
//  FileReader.hpp
//  ImageBrowser
//
//  Created by John Matthew Weston on 6/27/18.
//

#ifndef FileReader_hpp
#define FileReader_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#import "../Adapters/dcmlite/dcmlite.h"

class FileReader
{
public:
    FileReader();
    
    void Read( const std::string fileName );
    void Dump( std::string fileName );
    void ReadPixelData(const std::string& file_path);
};

#endif /* FileReader_hpp */
