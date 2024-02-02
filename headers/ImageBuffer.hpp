#include "Pixel.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <boost/gil/extension/io/bmp.hpp>

template<int N, int M> 
class ImageBuffer {
private:
    Pixel buffer[M][N];
    
public:
    ImageBuffer() = default;

    /**
     * @brief Copy constructor for ImageBuffer class.
     * 
     * This constructor creates a new ImageBuffer object by copying the contents of another ImageBuffer object.
     * The pixel values of the new object are interpolated from the pixel values of the original object.
     * 
     * @param other The ImageBuffer object to be copied.
     */
    template<int n, int m>
    ImageBuffer(const ImageBuffer<n,m>& other) {
        for (int i = 0; i < N; i++ ) {
            for (int k = 0; k < M; k++) {
                int x = (int)((i/(double)N) *n);
                int y = (int)((k/(double)M) *m);
                (*this)(i, k) = other(x, y);
            }
        }
    }

    ImageBuffer(const char* name)  {
        using namespace boost;
        gil::rgb8_image_t img;
        gil::read_image(name, img, gil::bmp_tag());

        auto img_view = gil::view(img);

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N ; n++) {
                int x = (int)((n/(double)N) *img_view.dimensions().x);
                int y = (int)((m/(double)M) *img_view.dimensions().y);

                auto pixel = img_view(x, y);

                buffer[m][n].r = (uint8_t)gil::at_c<0>(pixel);
                buffer[m][n].g = (uint8_t)gil::at_c<1>(pixel);
                buffer[m][n].b = (uint8_t)gil::at_c<2>(pixel);
            }            
        }

    }



    // #ifdef __ORDER_LITTLE_ENDIAN__
    // /**
    //  * @brief Constructs an ImageBuffer object from a BMP file.
    //  * 
    //  * Source: https://en.wikipedia.org/wiki/BMP_file_format#Example_2
    //  * 
    //  * @param filename The name of the BMP file to read from.
    //  * @throws std::runtime_error If the file could not be opened, or if the file is not a valid or supported BMP file.
    //  * @throws std::runtime_error If the file is the wrong size for this object.
    //  * @throws std::runtime_error If the file is not a 24-bit BMP file.
    //  * 
    // */
    // ImageBuffer(const char* const filename) {
    //     std::ifstream file(filename);
    //     if (!file) {
    //         throw std::runtime_error("Could not open file");
    //     }
    //     file.seekg(0, std::ios::beg);

    //     struct __attribute__((packed)) BITMAPFILEHEADER {
    //         char fheader[2];
    //         uint32_t size;
    //         uint16_t reserved1;
    //         uint16_t reserved2;
    //         uint32_t data_start;
    //     } file_header;
    //     file.read((char*)&file_header, sizeof(file_header));

    //     if (file_header.fheader[0] != 'B' || file_header.fheader[1] != 'M') {
    //         throw std::runtime_error(std::string("File ") + filename + " is not a valid BMP file.\n");
    //     }

    //     enum Compression : uint32_t {
    //             BI_RGB = 0,
    //             BI_RLE8 = 1,
    //             BI_RLE4 = 2,
    //             BI_BITFIELDS = 3,
    //             BI_JPEG = 4,
    //             BI_PNG = 5,
    //             BI_ALPHABITFIELDS = 6,
    //             BI_CMYK = 11,
    //             BI_CMYKRLE8 = 12,
    //             BI_CMYKRLE4 = 13
    //     };

    //     struct __attribute__((packed)) BITMAPV5HEADER {
    //         uint32_t header_size;
    //         uint32_t width;
    //         uint32_t height;
    //         uint16_t color_planes;
    //         uint16_t bits_per_pixel;
    //         Compression compression_type;
    //         uint32_t image_size;
    //         uint32_t x_pixels_per_meter;
    //         uint32_t y_pixels_per_meter;
    //         uint32_t colors_in_color_table;
    //         uint32_t important_color_count;
    //         uint32_t red_mask;
    //         uint32_t green_mask;
    //         uint32_t blue_mask;
    //         uint32_t alpha_mask;
    //         uint32_t color_space_type;
    //         uint32_t red_x;
    //         uint32_t red_y;
    //         uint32_t red_z;
    //         uint32_t green_x;
    //         uint32_t green_y;
    //         uint32_t green_z;
    //         uint32_t blue_x;
    //         uint32_t blue_y;
    //         uint32_t blue_z;
    //         uint32_t gamma_red;
    //         uint32_t gamma_green;
    //         uint32_t gamma_blue;
    //         uint32_t intent;
    //         uint32_t profile_data;
    //         uint32_t profile_size;
    //         uint32_t reserved;
    //     } info_header;
    //     file.read((char*)&info_header, sizeof(info_header.header_size));

    //     if (info_header.header_size != 12 && 
    //         info_header.header_size != 40 && 
    //         info_header.header_size != 52 && 
    //         info_header.header_size != 56 && 
    //         info_header.header_size != 108 && 
    //         info_header.header_size != 124) {
    //         std::runtime_error(std::string("Header size of ") + filename + " is of invalid size " + std::to_string(info_header.header_size) + "\n");
    //     }
    //     file.seekg(sizeof(file_header), std::ios::beg);
    //     file.read((char*)&info_header, info_header.header_size);

    //     if (file_header.fheader[0] != 'B' || file_header.fheader[1] != 'M') {
    //         throw std::runtime_error(std::string("File ") + filename + " is not a valid BMP file.\n");
    //     }
    //     if (info_header.width > N || info_header.height > M) {
    //         throw std::runtime_error(std::string("File ") + filename + " is the wrong size for this object.\n");
    //     }


    //     if (info_header.compression_type == BI_BITFIELDS) {
    //         uint32_t masks[3];
    //         file.read((char*)masks, sizeof(masks));
    //     }
    //     else if (info_header.compression_type == BI_ALPHABITFIELDS) {
    //         uint32_t masks[4];
    //         file.read((char*)masks, sizeof(masks));
    //     }

    //     if (info_header.bits_per_pixel != 24) {
    //         throw std::runtime_error(std::string("File ") + filename + " is not a 24-bit BMP file.\n");
    //     }
        
    //     file.seekg(file_header.data_start, std::ios::beg);
    //     for (int row = M-1; row >=0; row--) {
    //         int row_byte_width = std::ceil(info_header.bits_per_pixel*info_header.width/32.0)*4;
    //         file.read((char*)buffer[row], N*sizeof(Pixel));
    //         for (Pixel& p : buffer[row]) {
    //             auto temp = p.r;
    //             p.r = p.b;
    //             p.b = temp;
    //         }
    //         file.seekg(row_byte_width - info_header.width*sizeof(Pixel), std::ios::cur);
    //     }  
    //     file.close();
    // }
    // #endif

    /**
     * @brief Accesses the pixel at the specified coordinates.
     * 
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return A reference to the pixel at the specified coordinates.
     */
    inline constexpr Pixel& operator()(const int x, const int y) {
        return buffer[y][x];
    }
    /**
     * @brief Accesses the pixel at the specified coordinates.
     *
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @return A reference to the pixel at the specified coordinates.
     */
    inline constexpr const Pixel& operator()(const int x, const int y) const {
        return buffer[y][x];
    }

    template<int n, int m>
    constexpr ImageBuffer<n, m> downscaleAVG() {
        ImageBuffer<n, m> newImage;
        constexpr double scaleY = (double)M/(double)m, scaleX = (double)N/(double)n;
        std::cout<< scaleY << " " << scaleX << std::endl;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                double r = 0, g = 0, b = 0;
                int count = 0;
                for (int y1 = (int)(y*scaleY); y1 < (int)((y+1)*scaleY); y1++) {
                    for (int x1 = (int)(x*scaleX); x1 < (int)((x+1)*scaleX); x1++) {
                        r += (*this)(x1, y1).r;
                        g += (*this)(x1, y1).g;
                        b += (*this)(x1, y1).b;
                        count++;
                    }
                }
                newImage(x, y).r = (uint8_t)(r/count);
                newImage(x, y).g = (uint8_t)(g/count);
                newImage(x, y).b = (uint8_t)(b/count);
            }
        }
        //return newImage;
        return newImage;
    }
    

};
