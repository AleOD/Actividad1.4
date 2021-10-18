#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
#define NUM_THREADS 1

int main()
{
    omp_set_num_threads(NUM_THREADS);
    FILE *image, *outputImage, *lecturas;
    image = fopen("f1b.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("blurred.bmp","wb");    //Imagen transformada
    long width;
    long height;
    unsigned char r, g, b;               //Pixel
    unsigned char* ptr;

    unsigned char xx[54];
    int cuenta = 0;
    for(int i=0; i<54; i++) {
      xx[i] = fgetc(image);
      fputc(xx[i], outputImage);   //Copia cabecera a nueva imagen
    }
    width = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
    height = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];

    ptr = (unsigned char*)malloc(height*width*3* sizeof(unsigned char));

    #pragma omp parallel
    {
      while(!feof(image)){
        b = fgetc(image);
        g = fgetc(image);
        r = fgetc(image);

        unsigned char pixel = 0.21*r+0.72*g+0.07*b;

        ptr[cuenta] = pixel; 
        cuenta++;
      }
    }

    int x=0, pix=1;
    int start=0, end=width-1;
    int pix_val=7;//pixel del centro de la matriz de 13x13

    const double startTime = omp_get_wtime();
    #pragma omp parallel
    {
        cuenta = width;
        #pragma omp for schedule(dynamic)
            for (int i = 0; i < height*width; i++){
                if(x <=4 || x>=(height-5) || i==(start) && i<=(start+4) || i==(end) && i>=(end-4)){
                  fputc(ptr[i], outputImage);
                  fputc(ptr[i], outputImage);
                  fputc(ptr[i], outputImage);
                }
                else{
                    for(int j = 0; j < 7 ; j++){
                      pix = i+(width*j); 
                      pix_val = pix_val + ((ptr[pix]+ptr[pix-1]+ptr[pix-2]+ptr[pix-3]+ptr[pix-4]+ptr[pix-5]+ptr[pix-6]+ptr[pix+1]+ptr[pix+2]+ptr[pix+3]+ptr[pix+4]+ptr[pix+5]+ptr[pix+1]+ptr[pix+2]+ptr[pix+3]+ptr[pix+4]+ptr[pix+6])/169);
                    }   

                    fputc(pix_val, outputImage);
                    fputc(pix_val, outputImage);
                    fputc(pix_val, outputImage);
                    pix_val=0;
                }
                cuenta--;
        
                if(cuenta == 0){
                    cuenta = width;
                    x++;
                    start=x*width;
                    end = start+width-1;       
                }
            }
    }

    const double endTime = omp_get_wtime();
    printf("%i\t", (NUM_THREADS));
    printf("%lf\n", (endTime - startTime));

    free(ptr);
    fclose(image);
    fclose(outputImage);

    return 0;
}
