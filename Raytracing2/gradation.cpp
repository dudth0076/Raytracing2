//#include "Color.h"
//#include "Vec3.h"
//#include <fstream> // 파일 출력
//#include <iostream>
//
//int main()
//{
//    // Image
//    int ImageWidth = 256;
//    int ImageHeight = 256;
//
//    // Output  ← [CUSTOM] 파일 스트림 열기
//    std::ofstream outFile("image.ppm");
//
//    // Render
//    outFile << "P3\n" << ImageWidth << ' ' << ImageHeight << "\n255\n";   // cout → outFile
//
//    for (int j = 0; j < ImageHeight; j++)
//    {
//        std::clog << "\rScanlines remaining: " << (ImageHeight - j) << ' ' << std::flush;  // 로그는 콘솔 유지
//        for (int i = 0; i < ImageWidth; i++)
//        {
//            auto PixelColor = Color(double(i) / (ImageWidth - 1), double(j) / (ImageHeight - 1), 0);
//            WriteColor(outFile, PixelColor); // cout → outFile
//        }
//    }
//
//    outFile.close();                         // ← [CUSTOM] 파일 닫기
//    std::clog << "\rDone.                 \n";
//   return 0;
//}