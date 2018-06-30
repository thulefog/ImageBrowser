//
//  FileReaderBridge.m
//  ImageBrowser
//
//  Created by John Matthew Weston on 6/27/18.
//

#import <Foundation/Foundation.h>

#import "FileReaderBridge.h"
#import "FileReader.hpp"

@implementation FileReaderBridge

- (id)Read:(NSString *)mediaFileSetFileName;
{
    
    FileReader *reader = new FileReader();
    std::string fileNameString = std::string([mediaFileSetFileName UTF8String]);
    reader->Read( fileNameString );
    delete reader;
    
}

@end

