#include <stdio.h>

__u_short chksum( __u_short *buf, int count)
{
	register __u_long sum = 0;
	while (count--)
	{
		sum += *buf; buf++;
		if (sum & 0xFFFF0000)
		{
			sum &= 0xFFFF; sum++;
		}
	}
	return ~(sum & 0xFFFF);
}

__u_short seq[] = {0x46c0, 0x0028, 0x0000, 0x4000, 0x1850, 0xc0a8, 0x2b01,
                   0x0010, 0xe000, 0x0016, 0x9404, 0x0000
                  };

__u_short seq1[] = {0x4500 , 0x0073 , 0x0000 , 0x4000 , 0x4011 , 0xb861 , 0xc0a8 , 0x0001 , 0xc0a8 , 0x00c7};
int main()
{
	printf("%x\n", chksum(seq1, 12) );

}
