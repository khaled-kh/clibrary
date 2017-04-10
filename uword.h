#ifndef UWORD_H
#define UWORD_H

#include <stdio.h>
#include <limits.h>

union _UWORD
{
    unsigned char              bytes[10];

    int Int;   unsigned long long ULLong;
    char Char;    unsigned short  UShort;
    long   Long;    unsigned  long ULong;
    short   Short;   unsigned char UChar;
    long long LLong;   unsigned int UInt;
    float       Float;    double  Double;
    long double LDouble;
};

typedef union _UWORD UWORD;

UWORD read_uword(FILE *fp, size_t n){ UWORD w; fread (w.bytes, sizeof(unsigned char), n, fp); return w; }
void write_uword(FILE *fp, size_t n, UWORD w){ fwrite(w.bytes, sizeof(unsigned char), n, fp); }

char               read_char   (FILE *fp){ return read_uword(fp,sizeof(         char     )).Char;    }
short              read_short  (FILE *fp){ return read_uword(fp,sizeof(         short    )).Short;   }
int                read_int    (FILE *fp){ return read_uword(fp,sizeof(         int      )).Int;     }
long               read_long   (FILE *fp){ return read_uword(fp,sizeof(         long     )).Long;    }
long long          read_llong  (FILE *fp){ return read_uword(fp,sizeof(         long long)).LLong;   }
float              read_float  (FILE *fp){ return read_uword(fp,sizeof(         float    )).Float;   }
double             read_double (FILE *fp){ return read_uword(fp,sizeof(         double   )).Double;  }
long double        read_ldouble(FILE *fp){ return read_uword(fp,sizeof(    long double   )).LDouble; }
unsigned char      read_uchar  (FILE *fp){ return read_uword(fp,sizeof(unsigned char     )).UChar;   }
unsigned short     read_ushort (FILE *fp){ return read_uword(fp,sizeof(unsigned short    )).UShort;  }
unsigned int       read_uint   (FILE *fp){ return read_uword(fp,sizeof(unsigned int      )).UInt;    }
unsigned long      read_ulong  (FILE *fp){ return read_uword(fp,sizeof(unsigned long     )).ULong;   }
unsigned long long read_ullong (FILE *fp){ return read_uword(fp,sizeof(unsigned long long)).ULLong;  }

void write_char   (FILE *fp,               char d){ UWORD w; w.Char=d;    write_uword(fp,sizeof(              char),w); }
void write_short  (FILE *fp,              short d){ UWORD w; w.Short=d;   write_uword(fp,sizeof(             short),w); }
void write_int    (FILE *fp,                int d){ UWORD w; w.Int=d;     write_uword(fp,sizeof(               int),w); }
void write_long   (FILE *fp,               long d){ UWORD w; w.Long=d;    write_uword(fp,sizeof(              long),w); }
void write_llong  (FILE *fp,          long long d){ UWORD w; w.LLong=d;   write_uword(fp,sizeof(         long long),w); }
void write_float  (FILE *fp,              float d){ UWORD w; w.Float=d;   write_uword(fp,sizeof(             float),w); }
void write_double (FILE *fp,             double d){ UWORD w; w.Double=d;  write_uword(fp,sizeof(            double),w); }
void write_ldouble(FILE *fp, long        double d){ UWORD w; w.LDouble=d; write_uword(fp,sizeof(long        double),w); }
void write_uchar  (FILE *fp, unsigned      char d){ UWORD w; w.UChar=d;   write_uword(fp,sizeof(unsigned      char),w); }
void write_ushort (FILE *fp, unsigned     short d){ UWORD w; w.UShort=d;  write_uword(fp,sizeof(unsigned     short),w); }
void write_uint   (FILE *fp, unsigned       int d){ UWORD w; w.UInt=d;    write_uword(fp,sizeof(unsigned       int),w); }
void write_ulong  (FILE *fp, unsigned      long d){ UWORD w; w.ULong=d;   write_uword(fp,sizeof(unsigned      long),w); }
void write_ullong (FILE *fp, unsigned long long d){ UWORD w; w.ULLong=d;  write_uword(fp,sizeof(unsigned long long),w); }

#endif