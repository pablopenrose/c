#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "init.h"

void load_chunk_id (FILE *fp, char * chunk_id) {
    int i;
    for (i = 0; i < 4; i++) {
        chunk_id[i] = fgetc(fp); 
    }   

}

void load_chunk_size (FILE *fp,  char * chunk_size) {
    int i;
    unsigned int temp[4];
    for (i = 0; i < 4; i++) {
        temp[i] = fgetc(fp); 
    }


}

void load_format (FILE *fp, char * format) {
    int i;
    for (i = 0; i < 4; i++) {
        format[i] = fgetc(fp); 
    }   
    format[i] = '\0';

}

void load_sub_chunk_a_id (FILE *fp, char * sub_chunk_a_id) {
    int i;
    for (i = 0; i < 4; i++) {
        sub_chunk_a_id[i] = fgetc(fp);
    }
    sub_chunk_a_id[i] = '\0';

}

void load_sub_chunk_a_size (FILE *fp, char * sub_chunk_a_size) {
    int i;
    for (i = 0; i < 4; i++) {
        sub_chunk_a_size[i] = ((int)fgetc(fp));
    }
    sub_chunk_a_size[i] = '\0';
    
}

void load_audio_format (FILE * fp, char * audio_format) {
    int i;
    char temp[5];
    for (i = 0; i < 2; i++) {
        temp[i] = fgetc(fp);
    }
    i = 0;
    for (i = 0; i < 2; i++) {
        printf("%c ", temp[i]);
    }
    audio_format[0] = temp[0];

}

void load_num_channels (FILE * fp, char * num_channels) {
    int i;
    for (i = 0; i < 2; i++) {
        num_channels[i] = ((int)fgetc(fp));
    }
    num_channels[i] = '\0';

}

void load_sample_rate (FILE * fp, char * sample_rate) {
    unsigned int i = 0;
    for (i = 0; i < 4; i++) {
        *(sample_rate+i) = fgetc(fp);
    }

}

void load_byte_rate (FILE * fp, char * byte_rate) {
    int i;
    for (i = 0; i < 4; i++) {
        byte_rate[i] = (fgetc(fp)); 
    }
    byte_rate[i] = '\0';

}

void load_block_align (FILE * fp, char * block_align) {
    int i;
    for (i = 0; i < 2; i++) {
        block_align[i] = fgetc(fp);
    }
    block_align[i] = '\0';

}

void load_bits_per_sample (FILE * fp, char * bits_per_sample) {
    int i;
    for (i = 0; i < 2; i++) {
        bits_per_sample[i] = fgetc(fp);
    }
    bits_per_sample[i] = '\0';
}

void load_data_label (FILE * fp, char * data_label) {
    int i;
    for (i = 0; i < 4; i++) {
       data_label[i] = fgetc(fp); 
    }
    data_label[i] = '\0';

}

void load_data_block_length (FILE *fp , char * data_block_length) {

    int i;
    for (int i; i < 4; i++) {
        data_block_length[i] = fgetc(fp);
    }
    
}

void load_frames (FILE * fp, char * frames) {

    int i = 0; 
    while ((frames[i] = fgetc(fp)) != EOF) {
       printf("%c",  *((frames+i))); 
       i++;
    }
    frames[i] = '\0';
    printf ("\ncount:%d\t", i);

}

void print_frames (FILE * fp) {
    int c, d, flag = 0;
    while ((c = fgetc(fp)) != EOF && ((d = fgetc(fp)) != EOF)) {
        if (flag % 2) {
            /* printf(" "); */ 
            flag = 0;
        }
        else {
            flag++;
        }
        /* printf("0x%x0x%x ", c, d); */
    }

}
