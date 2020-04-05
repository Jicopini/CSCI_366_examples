#include <iostream>
#include <fstream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>

using namespace std;

/**
 * An example of how to use cereal serialization and deserialization functions
 */
int main() {
   string fname = "array.json";

   // remove any old serialization files
   remove(fname.c_str());

   // create an integer array
   //vector< int > array1(2);

    std::vector<std::vector<int>> array1;
    array1.resize(10, std::vector<int>(10, 0));

   int HIT = 1;
   int result = HIT;

   /*
    string file = "player_1.shot.json";
    ofstream outFile(file);
    cereal::JSONOutputArchive write_archive(outFile);
    write_archive(CEREAL_NVP(result));
    write_archive.finishNode();
    outFile.close();
    */

    //ifstream inFile(file);
    //cereal::JSONInputArchive read_archive(inFile); // initialize an archive on the file

   // set some value and print
   //array1[1] = 1;
   //printf("array1[0] = %d, array1[1] = %d\n", array1[0], array1[1]);

   // serialize the array

   ofstream array_ofp(fname); // create an output file stream
   cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
   write_archive(cereal::make_nvp("board", array1)); // serialize the data giving it a name
   write_archive.finishNode(); // wait for the writing process to finish
   array_ofp.close(); // close the file


   // create a two dimensional array for deserialization
   //vector< int > array2(2);
   /*
    std::vector<std::vector<int>> array2;
    array1.resize(2, std::vector<int>(2, 0));
    */

   // deserialize the array
   /*
   ifstream array_ifp(fname); // create an input file stream
   cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
   read_archive(array2); // deserialize the array
   array_ifp.close(); // close the file
    */

   // print the result of deserialization
   //printf("array2[0] = %d, array2[1] = %d\n", array2[0][0], array2[1][0]);


   return 0;
}
