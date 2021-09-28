#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *image, *outputImage, *lecturas, *fptr1, *fptr2, *fptr3, *fptr4;
    image = fopen("maze.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("out_dd.bmp","wb");    //Imagen transformada

    long width;
    long height;

    unsigned char r, g, b;  //Pixel

    int bl = 0, gr = 0, rd = 0, gry = 0;
    int red[255]   = {0};
    int green[255] = {0};
    int blue[255]  = {0};
    int gray[255]  = {0};

    unsigned char xx[54];
    int cuenta = 0;
    for(int i=0; i<54; i++) {
      xx[i] = fgetc(image);
      fputc(xx[i], outputImage);   //Copia cabecera a nueva imagen
    }

    width = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
    height = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];
    printf("Largo de la imagen en pixeles: %li\n",height);
    printf("width de la imagen en pixeles: %li\n",width);

    fptr1=fopen("red.txt","w");
    fptr2=fopen("green.txt","w");
    fptr3=fopen("blue.txt","w");
    fptr4=fopen("gray.txt","w");

    while(!feof(image)) {                                        
       b = fgetc(image);
       g = fgetc(image);
       r = fgetc(image);
       
       bl = blue[b]; 
       blue[b] = bl+1;

       gr = green[g];
       green[g] = gr+1;
      
        rd = red[r];
       red[r] = rd+1;

       unsigned char pixel = 0.21*r+0.72*g+0.07*b;
       fputc(pixel, outputImage);
       fputc(pixel, outputImage);
       fputc(pixel, outputImage);

      gry = gray[pixel];
      gray[pixel] = gry+1;
    }

    for (int i = 0; i<256; i++) {
        fprintf(fptr1, "%d\n",red[i]);
    }
    fclose(fptr1);

    for (int i = 0; i<256; i++) {
        fprintf(fptr2, "%d\n",green[i]);
    }
    fclose(fptr2);

    for (int i = 0; i<256; i++) {
        fprintf(fptr3, "%d\n",blue[i]);
    }
    fclose(fptr3);

    for (int i = 0; i<256; i++) {
        fprintf(fptr4, "%d\n",gray[i]);
    }
    fclose(fptr4);

    fclose(image);
    fclose(outputImage);
    return 0;
}