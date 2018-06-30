//
//  FileReader.cpp
//  ImageBrowser
//
//  Created by John Matthew Weston on 6/27/18.
//

#include "FileReader.hpp"


FileReader::FileReader()
{
    
}

void FileReader::Read( std::string fileName )
{
    
    dcmlite::DataSet data_set;
    dcmlite::FullReadHandler read_handler(&data_set);
    dcmlite::DicomReader reader(&read_handler);
    reader.ReadFile( fileName );

    this->Dump( fileName );
    this->ReadPixelData( fileName );
}

void FileReader::Dump( std::string fileName )
{
    
    dcmlite::DumpReadHandler read_handler;
    dcmlite::DicomReader reader(&read_handler);
    reader.ReadFile(fileName);

}
void FileReader::ReadPixelData(const std::string& file_path) {
    std::cout << "Read the specific tags." << std::endl;
    
    dcmlite::DataSet data_set;
    dcmlite::TagsReadHandler read_handler(&data_set);

    const dcmlite::Tag kTagPixelData(0x7FE0,0x0010);
    const dcmlite::Tag kTagRows(0x0028,0x0010);
    const dcmlite::Tag kTagColumns(0x0028,0x0011);
    
    // NOTE: Add order doesn't matter.
    read_handler.AddTag(kTagPixelData);
    read_handler.AddTag(kTagRows);
    read_handler.AddTag(kTagColumns);

    dcmlite::DicomReader reader(&read_handler);
    reader.ReadFile(file_path);
    
    boost::shared_array<char> buffer;
    //= new boost::shared_array<char>();
    std::size_t length;

    data_set.GetBuffer(kTagPixelData, &buffer, &length );
    std::uint16_t rows;
    std::uint16_t columns;
    
    data_set.GetUint16( kTagRows, &rows );
    data_set.GetUint16( kTagColumns, &columns );

    std::cout << "Pixel Data (0x7FE0,0010): read with buffer length: " << length << " "
              << " Rows: " << rows << " Columns: " << columns
              << std::endl;
    
    // NOTE: doesn't work very well...
    //dcmlite::PrintVisitor visitor( std::cout);
    //visitor.VisitDataSet( &data_set );
    
    std::cout << std::endl;
}
