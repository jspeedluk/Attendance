# Attendance Managemet System.
A C++ based Project created for the fullfillment of the Course : Software Engineering . 
included: Documentation(SRS.docx , SRS.pdf) , UML diagrams in the Appendix.
        Presentation(presentation.pptx , presentation.pdf) 
        and Code.
        
Datafiles include StudentsLists.txt , lectureDatesFile.txt , faculty_details.txt , presentCount.txt and Date folder all in root directory.

Instructions to compile
Either execute the bundled executable AMS-ubuntu file in root dirctory or follow the following steps:

Download cmake archive version 3.8+ from https://cmake.org/download/
Extract .tar.gz file into a directory, say <root>
Now run configuration script by command ./configure
Then run command make to build
Next cd to project director, say <project> (src/ here) and run command "<root>/bin/cmake build ." followed by "<root>/bin/cmake --build . --target -- -j 4
Now run executable by running command ./AMS
 
