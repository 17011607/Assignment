#include<stdio.h>
#include<stdint.h>

uint32_t ntohl(uint32_t argv);


int main(int argc, char **argv){
	FILE *f1 = fopen(argv[1], "rb");
	FILE *f2 = fopen(argv[2], "rb");
	uint32_t a;	
	uint32_t c;

	fread(&a, sizeof(a),1, f1);
	fread(&c, sizeof(c),1, f2);

	a = ntohl(a);
	c = ntohl(c);

	printf("%u(0x%X) + %u(0x%X) = %u(0x%X)",a,a,c,c,a+c,a+c);
}

uint32_t ntohl(uint32_t argv){
	return (argv&0x0000FF00) << 8 | (argv&0x000000FF) << 24 | (argv&0xFF000000) >> 24 | (argv&0x00FF0000) >> 8;
}
