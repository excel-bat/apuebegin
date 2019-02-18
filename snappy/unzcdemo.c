//
// Created by 单颖博 on 2018/12/12.
//

#include "unzcdemo.h"


#include <stdlib.h>
#include <stdio.h>
#include <zlib.h>




#define CHUNK_SIZE 0x4000

int main(int argc, char* argv[])
{
//    FILE* file;
//    uLong flen;
//    unsigned char* fbuf = NULL;
//    uLong ulen;
//    unsigned char* ubuf = NULL;
//
//    /* 通过命令行参数将srcfile文件的数据解压缩后存放到dstfile文件中 */
//    if(argc < 3)
//    {
//        printf("Usage: unzcdemo srcfile dstfile\n");
//        return -1;
//    }
//
//    if((file = fopen(argv[1], "rb")) == NULL)
//    {
//        printf("Can\'t open %s!\n", argv[1]);
//        return -1;
//    }
//    /* 装载源文件数据到缓冲区 */
//    fread(&ulen, sizeof(uLong), 1, file);	/* 获取缓冲区大小 */
//    fread(&flen, sizeof(uLong), 1, file);	/* 获取数据流大小 */
//    if((fbuf = (unsigned char*)malloc(sizeof(unsigned char) * flen)) == NULL)
//    {
//        printf("No enough memory!\n");
//        fclose(file);
//        return -1;
//    }
//    fread(fbuf, sizeof(unsigned char), flen, file);
//    /* 解压缩数据 */
//    if((ubuf = (unsigned char*)malloc(sizeof(unsigned char) * ulen)) == NULL)
//    {
//        printf("No enough memory!\n");
//        fclose(file);
//        return -1;
//    }
//    if(uncompress(ubuf, &ulen, fbuf, flen) != Z_OK)
//    {
//        printf("Uncompress %s failed!\n", argv[1]);
//        return -1;
//    }
//    fclose(file);
//
//    if((file = fopen(argv[2], "wb")) == NULL)
//    {
//        printf("Can\'t create %s!\n", argv[2]);
//        return -1;
//    }
//    /* 保存解压缩后的数据到目标文件 */
//    fwrite(ubuf, sizeof(unsigned char), ulen, file);
//    fclose(file);
//
//    free(fbuf);
//    free(ubuf);
//
//    return 0;
      char *source = "2304567fsfasesdafsdad";
      int source_len =11;
      char dest[CHUNK_SIZE] ;
      int dest_len = CHUNK_SIZE;

       int ret_code = def_chunk(source, source_len, dest, &dest_len);


//
//        int ret;
//        z_stream strm;
//
//        /* allocate deflate state */
//        strm.zalloc = Z_NULL;
//        strm.zfree = Z_NULL;
//        strm.opaque = Z_NULL;
//        ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
//        if (ret != Z_OK)
//            return -1;
//
//        strm.avail_in = source_len;
//        strm.next_in = (Bytef *)source;
//
//        strm.avail_out = &dest_len;
//        strm.next_out = (Bytef *) dest;
//        ret = deflate(&strm, Z_FINISH);    /* no bad return value */
//        if(ret != Z_STREAM_END || strm.avail_in != 0)
//        {
//            deflateEnd(&strm);
//            return -1;
//        }
//        &dest_len=&dest_len-strm.avail_out;
//        deflateEnd(&strm);
//        return 0;

}

 int
def_chunk(char *source, int source_len, char *dest, int *dest_len)
{
    int ret;
    z_stream strm;

    /* allocate deflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK)
        return -1;

    strm.avail_in = source_len;
    strm.next_in = (Bytef *)source;

    strm.avail_out = *dest_len;
    strm.next_out = (Bytef *) dest;
    ret = deflate(&strm, Z_FINISH);    /* no bad return value */
    //ret = deflateInit2(&strm, Z_DEFAULT_COMPRESSION,Z_DEFLATED,MAX_WBITS +16,8,Z_DEFAULT_STRATEGY);

    if(ret != Z_STREAM_END || strm.avail_in != 0)
    {
        deflateEnd(&strm);
        return -1;
    }
    *dest_len=*dest_len-strm.avail_out;
    deflateEnd(&strm);
    printf(dest);
    return 0;
}
