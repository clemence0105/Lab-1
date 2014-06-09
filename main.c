
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int countlen (char *name, int *b);
char Func (char name[200], char name1[80], char name2[80], char name3[80], char ch, int *b, char name4[80]);
void Input (int *mass, unsigned int len, char *name, int *b);
void Summ (int *mass1, unsigned int len1, int *masssum, int *b);
void Copy (int *mass2, unsigned int len2,  int* masssum);
int Record (int *mass1, unsigned int len, char *name, int *b);
void Invent (int *mass1, unsigned int len1);
int *Dividing (int *mass1, unsigned int len1, int *mass2, unsigned int len2, int *b,char name3[80],  char name1[80], int k2, int *massdiv, int *massr);
void Multiply (int* mass1, unsigned int len1, int* mass2, unsigned int len2, int* massmul, unsigned int len,int *b);
void Funct1 (int* mass1, unsigned int len1, int* mass2, int* massmul,unsigned int k, int *b);
void Funct2 (int* massmul, unsigned int len1, unsigned int j);
void divide (int *mass1, int *mass2, unsigned int j,unsigned int n, int *massdiv, int *mass2_old, int* massr,int *b);
void clear (int *mass, unsigned int len);
int dividenumb(int *mass1, int *massdiv,unsigned int len2, int d, int *b);
void fpow (int* Z, unsigned int len1, int *N, unsigned int len2, char name3[80], int *b, int boo);
int* newarray (int* mass1, unsigned int len1, char name[80], int *b);
int deletez (int *mass1, unsigned int len1);
int compare (int *mass1, unsigned int len1, int *mass2);
void funsum (int *mass, int *mass1, unsigned int len1, int *mass2, unsigned int len2, int k2, int *b, char name3[80],int zap);
int divless (int *mass1, unsigned int len1, int *mass2, unsigned int len2, char name3[80], int *b,int *masssum, int k2);

int main (void)
{
	int k = 0,k2 = 0, n1, b[2], sd = 0;
	int *mass1 = NULL, *mass2 = NULL, *mass4 = NULL, *massmul, *mass21, *massr = NULL, *massdiv = NULL, *masssum = NULL;
	unsigned int len1, len2, len4;
	char name[200] = "\0", name1[80] = "\0", name2[80] = "\0", name3[80] = "\0",ch = '\0',name4[80] = "\0";
	b[0] = 10; b[1] = 0;
	printf ("<file 1> <operator> <file 2> <file 3> [-b] [mod]\n");
	gets(name);
	ch = Func(name, name1, name2, name3, ch, b, name4);
	if ((name1 == "\0") || (name2 == "\0") || (name3 == "\0") || (ch == '0'))
	{
		return 0;
	}
	len1 = countlen(name1, b);
	if (len1 != 0)
	{
		if ((b[1] == 0)||(ch == '/')||(ch == '%'))
		{
			mass1 = newarray(mass1,len1,name1,b);
		}
	}
	else return 0;
	len2 = countlen(name2,b);
	if (len2 != 0)
	{
		if((b[1] == 0)||(ch == '^') || (ch == '/') || (ch == '%'))
			mass2 = newarray(mass2, len2, name2, b);
	}
	else return 0;
	if ((b[1] == 1) && (ch != '/') && (ch != '%'))
	{
		len4 = countlen (name4, b);
		if (len4 != 0)
		{
			mass4 = newarray (mass4, len4, name4, b);
		}
		else return 0;
		mass1 = Dividing (mass1, len1, mass4, len4, b, name3, name1, 1, massdiv, massr);
		len1 = deletez (mass1, len1);
		if (ch!='^')
		{
			free(mass4);
			mass4 = newarray(mass4,len4,name4,b);
			mass2 = Dividing(mass2, len2, mass4, len4, b, name3, name2,1, massdiv, massr);
			len2 = deletez (mass2, len2);
		}
	}
	if (ch == '-')
	{
		k2 = 1;
		ch = '+';
	}
	if (ch == '%')
	{
		k2 = 1;
		ch = '/';
	}
	switch(ch)
	{
	case '*':
		massmul = (int*)malloc((len1+len2-1)*sizeof(int));
		clear(massmul,len1+len2-1);
		if (len1 > len2)
			Multiply(mass1, len1, mass2, len2, massmul, len1+len2-1, b);
		else
			Multiply(mass2, len2, mass1, len1, massmul, len1+len2-1, b);
		Record(massmul, len1+len2-1, name3, b);
		free(massmul);
		if (b[1] == 1)
		{
			len1 = countlen (name3, b);
			mass1 = newarray (mass1, len1, name3, b);
			len4 = countlen (name4, b);
			mass4 = newarray(mass4, len4, name4, b);
			sd = 0;
			sd = divless(mass1, len1, mass4, len4, name3, b, masssum, 1);
			if (sd == 1)
			{
				return 0;
			}
			mass1 = Dividing(mass1, len1, mass4, len4, b, name3, name3, 1, massdiv, massr);
			Record(mass1, len1, name3, b);
		}
		printf("");
		break;
	case '+':
		if (len1 > len2)
		{
			funsum(masssum, mass1, len1+1, mass2, len2, k2, b, name3, 1);
		}
		else
		{
			int min = 1;
			if (len1 == len2)
				min = compare(mass1, len1, mass2);
			if (min == 0)
				funsum(masssum, mass1, len1+1, mass2, len2, k2, b, name3, 1);
			else
			{
				if (k2 == 1)
					funsum(masssum, mass2, len2+1, mass1, len1, 3, b, name3,1);
				else
					funsum(masssum, mass2, len2+1, mass1, len1, k2, b, name3, 1);
			}
		}
		if (b[1] == 1)
		{
			len1 = countlen(name3, b);
			mass1 = newarray(mass1, len1, name3, b);
			len4 = countlen(name4, b);
			mass4 = newarray(mass4, len4, name4, b);
			sd = 0;
			sd = divless(mass1, len1, mass4, len4, name3, b, masssum, 1);
			if (sd == 1)
			{
				return 0;
			}
			mass1 = Dividing(mass1, len1, mass4, len4, b, name3, name3, 1, massdiv, massr);
			Record(mass1, len1, name3, b);
		}
		printf("");
		break;
	case '/':
		sd = 0;
		sd=divless(mass1, len1, mass2, len2, name3, b, masssum, k2);
		if (sd == 1)
		{
			return 0;
		}
		mass1 = Dividing(mass1, len1, mass2, len2, b, name3, name1 ,k2, massdiv, massr);
		if (b[1] == 1)
		{
			if (k2 == 0)
			{
				len1 = countlen(name3, b);
				mass1 = newarray(mass1, len1, name3, b);
			}
			len4 = countlen(name4, b);
			mass4 = newarray(mass4, len4, name4, b);
			sd = 0;
			sd = divless(mass1, len1, mass4, len4, name3,b,masssum,1);
			if (sd==1)
			{
				return 0;
			}
			mass1 = Dividing(mass1, len1, mass4, len4, b,name3,name3, 1, massdiv, massr);
			Record(mass1, len1, name3, b);
		}
		printf("");
		break;
	case '^':
		fpow(mass1, len1, mass2, len2, name3, b, 1);
		if (b[1] == 1)
		{
			len1 = countlen(name3, b);
			mass1 = newarray(mass1, len1, name3, b);
			len4 = countlen(name4, b);
			mass4 = newarray(mass4, len4, name4, b);
			sd = 0;
			sd = divless(mass1, len1, mass4, len4, name3, b, masssum, 1);
			if (sd == 1)
			{
				return 0;
			}
			mass1 = Dividing(mass1, len1, mass4, len4, b, name3, name3, 1, massdiv, massr);
			Record(mass1, len1, name3, b);
		}
		printf("");
		break;
	default:
		break;
	}
	free (mass1);
	free (mass2);
	return 0;
}
unsigned int countlen(char *name, int *b)
{
	FILE *fp;
	int len = 0;
	char c[3];
	if (b[0] == 10)
		strcpy(c, "r");
	else
		strcpy(c, "rb");
	fp = fopen(name, c);
	if (NULL == fp)
	{
		printf ("Error!\n");
		return 0;
	}
	fclose(fp);
	fp = fopen(name, c);
	char ch;
	ch = getc(fp);
	if (((ch != '-') && (ch != '+')) || (b[0] == 256))
		len++;
	while(!feof(fp))
	{
		len++;
		ch = getc(fp);
	}
	fclose(fp);
	return len;
}
char Func (char name[200], char name1[80], char name2[80], char name3[80], char ch, int *b, char name4[80])
{
	char ch1;
	int i = 0, k = 0;
	ch1 = name[0];
	while (ch1 != ' ')
	{
		name1[k] = name[i];
		i++; k++;
		ch1 = name[i];
	}
	name1[k] = '\0';
	i++;
	ch = name[i];
	if (name[i+1] != ' ')
	{
		return ch = '0';
	}
	k = 0;
	i = i + 2;
	ch1 = name[i];
	while (ch1 != ' ')
	{
		name2[k] = name[i];
		i++;
		ch1 = name[i];
		k++;
	}
	name2[k] = '\0';
	k = 0;
	i++;
	ch1 = name[i];
	while ((ch1 != '\0') && (ch1 != ' '))
	{
		name3[k] = name[i];
		i++;
		ch1 = name[i];
		k++;
	}
	name3[k] = '\0';

	if ((name[i+1] == '-') && (name[i+2] == 'b'))
	{
		b[0] = 256;
		i = i+3;
	}
	k = 0;
	ch1 = name[i];
	if (ch1 == ' ')
	{
		b[1] = 1;
		ch1 = name[i];
		i++;
		while (ch1 != '\0')
		{
			name4[k] = name[i];
			i++;
			ch1 = name[i];
			k++;
		}
		name4[k] = '\0';
	}
	return ch;
}
void Input(int* mass, unsigned int len, char *name, int *b)
{
	if (b[0]==10)
	{
		FILE *fp = fopen(name,"r");
		int k = len - 1;
		char ch;
		ch = getc(fp);
		if (ch != '-')
		{
			mass[0] = '+';
			if (ch == '+')
			{
				ch = getc(fp);
			}
			mass[len-1] = ch-'0';
			k--;
		}
		else mass[0] = '-';
		for (int i = k; i > 0; i--)
		{
			ch = getc(fp);
			mass[i] = ch - '0';
		}
		fclose(fp);
	}
	else
	{
		FILE *fp = fopen (name,"rb");
		mass[1] = getc(fp);
		for (int i = 2; i < len; i++)
		{
			mass[i] = getc(fp);
		}
		fclose(fp);
	}
}
void Copy (int*mass2, unsigned int len2, int* masssum)
{
	masssum[0] = mass2[0];
	for (int i = len2-1; i > 0; i--)
	{
		masssum[i] = mass2[i];
	}
}
void Summ(int*mass1, unsigned int len1, int* masssum, int *b)
{
	int sum = 0;
	if (mass1[0] == masssum[0])
	{
		//Cложение
		for (int i = 1; i < len1; i++)
		{
			sum = masssum[i]+mass1[i];
			if (sum > b[0]-1)
			{
				masssum[i+1] = masssum[i+1] + 1;
				masssum[i] = sum - b[0];
			}
			else masssum[i] = sum;
		}
	}
	else
	{
		//вычитание
		for (int i = 1; i < len1; i++)
		{
			sum = masssum[i] - mass1[i];
			if (sum < 0)
			{
				masssum[i+1] = masssum[i+1] - 1;
				masssum[i] = b[0] + sum;
			}
			else masssum[i] = sum;
		}
		if (masssum[len1] < 0)
		{
			masssum[len1] = b[0] + masssum[len1];
			masssum[len1+1]--;
		}
	}
}
int Record (int* mass1, unsigned int len, char *name, int *b)
{
	len = deletez (mass1, len);
	if(b[0] == 10)
	{
		FILE *fp;
		fp = fopen(name, "w+");
		if (fp == NULL)
		{
			printf ("Сannot open the file!\n");
			return 0;
		}
		fclose (fp);
		fp = fopen(name, "w+");
		if ((mass1[1] == 0) && (len == 1))
		{
			char ch;
			char c = mass1[1] + 48;
			putc(c, fp);
			fclose(fp);
			return 0;
		}
		if (mass1[0] == '-')
		{
			char c = mass1[0];
			putc(c, fp);
		}
		for(int i = len-1; i > 0; i--)
		{
			char c = mass1[i] + 48;
			putc(c, fp);
		}
		fclose(fp);
	}
	else
	{
		FILE *fp;
		fp = fopen(name, "wb+");
		if (fp == NULL)
		{
			printf ("Error!");
			return 0;
		}
		fclose (fp);
		fp = fopen(name,"wb+");
		putc (mass1[1], fp);
		for (int i = 2; i < len; i++)
		{
			putc(mass1[i], fp);
		}
		fclose(fp);
	}
	return 0;
}
void Invent(int* mass1, unsigned int len1)
{
	if (mass1[0] == '-')
		mass1[0] = '+';
	else
		mass1[0] = '-';
}
void Multiply(int* mass1, unsigned int len1, int* mass2, unsigned int len2, int* massmul, unsigned int len, int *b)
{
	int *massmul2 = (int*)malloc((len1+len2-1)*sizeof(int));
	int s1 = 0;
	for (int i = 0; i < len1+len2-1; i++)
		massmul2[i] = 0;

	if (mass1[0] == mass2[0])
	{
		massmul[0] = '+';
		massmul2[0] = '+';
	}
	else
	{
		massmul[0] = '-';
		massmul2[0] = '-';
	}
	Funct1 (mass1, len1, mass2, massmul2, 1, b);
	Copy (massmul2, len1+1, massmul);
	for (int i = 1; i < len1+len2-1; i++)
		massmul2[i] = 0;
	for (int j = 2; j < len2; j++)
	{
		for (int i = 1; i < len1+len2-1; i++)
			massmul2[i] = 0;
		Funct1(mass1, len1, mass2, massmul2, j, b);
		Funct2(massmul2, len1, j-1);
		Summ(massmul2, len1+len2-1, massmul, b);
	}
	free(massmul2);
}
void Funct1(int* mass1, unsigned int len1, int* mass2, int* massmul, unsigned int k, int *b)
{
	int s1 = 0, s2 = 0, s3;
	for (int i = 1; i < len1; i++)
	{
		if (mass1[i]*mass2[k] < b[0])
		{
			s2 = mass1[i]*mass2[k];
			if (massmul[i]+s2 < b[0])
			{
				massmul[i] = massmul[i] + s2;
			}
			else
			{
				s3 = massmul[i] + s2;
				massmul[i] = s3 % b[0];
				massmul[i+1] = massmul[i+1] + 1;
			}
		}
		else
		{
			massmul[i+1] = mass1[i]*mass2[k]/b[0];
			s2 = (mass1[i]*mass2[k]) % b[0];
			if (massmul[i]+s2 < b[0])
			{
				massmul[i] = massmul[i] + s2;
			}
			else
			{
				s3 = massmul[i] + s2;
				massmul[i] = s3 % b[0];
				massmul[i+1] = massmul[i+1] + 1;
			}
		}
	}
}
void Funct2 ( int* massmul, unsigned int len1, unsigned int j)
{
	for (int i = len1; i > 0; i--)
		massmul[i+j] = massmul[i];
	for (int i = 1; i < j+1; i++)
		massmul[i] = 0;
}
void divide(int *mass1, int *mass2, unsigned int j, unsigned int n, int *massdiv, int *mass2_old, int* massr, int *b)
{
	int *bb;
	int q = 0,r = 0, min = 0;
	int *massn = NULL;
	do
	{
		massn = (int*)malloc((n+5)*sizeof(int));
	} while (massn == NULL);

	massn = (int*)malloc((n+5)*sizeof(int));
	massn[0] = 0;
	clear(massn, n+4);
	int *mass22 = (int*)malloc((n+3)*sizeof(int));
	clear(mass22, n+2);
	q = (mass1[j+n]*b[0]+mass1[j+n-1])/mass2_old[n];
	r = (mass1[j+n]*b[0]+mass1[j+n-1])%mass2_old[n];
	if ((q*mass2_old[n-1]>b[0]*r+mass1[j+n-2]) || (q==b[0]))
	{
		q--;
		r = r + mass2_old[n];
		if ((q*mass2_old[n-1] > b[0]*r+mass1[j+n-2]) || (q==b[0]))
		{
			q--;
			r = r + mass2_old[n-1];
		}
	}
	int mass[2];
	mass[0] = '+';
	mass[1] = q;
	Funct1(mass2, n+1, mass, mass22, 1, b);
	mass22[0] = '-';
	massn[0] = '+';
	int k = 0;
	for (int i = j + n; i > j - 1; i--)
	{
		massn[n-k+1] = mass1[i];
		mass1[i] = 0;
		k++;
	}
	min = 0;
	for (int i = n+1; i > 0; i--)
	{
		if (massn[i] != mass22[i])
		{
			if (massn[i] < mass22[i])
			{
				min++;
				break;
			}
			else
			{
				break;
			}
		}
	}

	if (min > 0)
	{
		bb = (int*)malloc((n+4)*sizeof(int));
		clear (bb, n+2);
		bb[n] = 1;
		mass22[0] = '+';
		massn[0] = '-';
		Summ(massn, n+1, mass22, b);
		mass22[0] = '-';
		bb[0] = '+';
		Summ (mass22, n+1, bb, b);
		q--;
		bb[0] = '+';
		mass2_old[0] = '+';
		Summ (mass2_old, n+2, bb, b);
		bb[n]--;
		Copy(bb, n+1, massn);
		free(bb);
	}
	else
		Summ(mass22, n+2, massn, b);
	k = 0;
	for (int i = j + n; i > j - 1; i--)
	{
		mass1[i ] = massn[n-k+1];
		k++;
	}
	Copy(mass1, n+1, massr);
	massdiv[j] = q;
	free (massn);
	free (mass22);
}
void clear (int *mass, unsigned int len)
{
	for (int i = 0; i < len; i++)
		mass[i] = 0;
}
int dividenumb(int *mass1,int *massdiv,unsigned int len2,int d, int *b)
{
	int k = 0, n1 = len2 - 1;
	for (int i = len2-1; i > 0; i-- )
	{
		k = mass1[i] + k * b[0];
		if (k < d)
		{
			i--;
			n1--;
			k = k * b[0] + mass1[i];
			massdiv[n1] = k/d;
			k = k-d*massdiv[n1];
			n1--;
			if (i == 0)
			{
				k = mass1[i+1];
			}
		}
		else
		{
			if (k > b[0]-1)
			{
				massdiv[n1] = k/d;
				k = k-d*massdiv[n1];
				n1--;
			}
			else
			{
				massdiv[n1] = k/d;
				k = k%d;
				n1--;
			}
		}
	}
	return k;
}
void fpow(int* mass1, unsigned int len1, int *mass2, unsigned int len2, char name3[80],int *b,int boo)
{
	int *Y_new, *N_new, *Z_new;
	int *Z = (int*)malloc((len1)*sizeof(int));
	int *N = (int*)malloc((len2)*sizeof(int));
	clear(Z, len1);
	clear(N, len2);
	Copy(mass1, len1, Z);
	Copy(mass2, len2, N);
	int *Y = (int*)malloc((2)*sizeof(int));
	Y[1] = 1;
	Y[0] = '+';
	int k = -1, s = 0;
	int lenY = 2, lenZ = len1;
	do
	{
		N_new = (int*)malloc((len2)*sizeof(int));
		clear(N_new,len2);
		k = dividenumb(N, N_new, len2, 2, b);
		N_new[0] = '+';
		free(N);
		N = (int*)malloc((len2)*sizeof(int));
		clear(N, len2);
		Copy(N_new, len2, N);
		free(N_new);
		if (k == 1)
		{
			lenY = lenZ + lenY;
			Y_new = (int*)malloc((lenY)*sizeof(int));
			clear(Y_new,lenY);
			Multiply(Z, lenZ, Y, lenY-lenZ, Y_new, lenY, b);
			free(Y);
			Y = (int*)malloc((lenY)*sizeof(int));
			clear (Y, lenY);
			Copy (Y_new, lenY, Y);
			free (Y_new);
			for (int i = 1; i < len2; i++)
			{
				if (N[i] != 0)
				{
					s++;
				}
			}
			if (s == 0)
			{
				break;
			}
		}
		lenZ = 2 * lenZ;
		Z_new = (int*)malloc((lenZ)*sizeof(int));
		clear(Z_new, lenZ);
		Multiply(Z, lenZ/2, Z, lenZ/2, Z_new, lenZ, b);
		free(Z);
		Z = (int*)malloc((lenZ)*sizeof(int));
		clear(Z, lenZ);
		Copy(Z_new, lenZ, Z);
		free(Z_new);
		s = 0;
	} while (N != 0);
	if (boo != 0)
	{
		Record(Y, lenY, name3, b);
	}
	free(Z);
	free(Y);
}
int* newarray (int* mass1, unsigned int len1, char name[80], int *b)
{
	mass1 = (int*)malloc((len1*2)*sizeof(int));
	clear(mass1, len1);
	if (b[0] == 256)
		mass1[0] = '+';
	Input(mass1, len1, name, b);
	return mass1;
}
int *Dividing (int *mass1, unsigned int len1, int *mass2, unsigned int len2, int *b,char name3[80], char name1[80], int k2, int *massdiv, int *massr)
{
	int *masssum = NULL;
	free(mass1);
	int znak = 0;
	len1++;
	mass1 = (int*)malloc((len1+1)*sizeof(int));
	clear (mass1, len1+1);
	Input (mass1, len1-1, name1, b);
	znak = mass1[0];
	int *mass1copy = (int*)malloc((len1+1)*sizeof(int));
	int *mass2copy = (int*)malloc((len2)*sizeof(int));
	Copy(mass1, len1, mass1copy);
	Copy(mass2, len2, mass2copy);
	int numb = 0, d = 0, m = 0, *massmul, k = 0;
	massr = (int*)malloc((len2)*sizeof(int));
	clear(massr, len2);
	if ((mass1[0] == mass2[0]) && (b[0] == 10))
		numb = '+';
	else
		numb = '-';
	if (len2 > 2)
	{
		d = b[0]/(mass2[len2-1]+1);
		if (d == 1)
		{
			mass1[len1-1] = 0;
		}
		else
		{
			int mass[2];
			mass[1] = d;
			int* mass11;
			mass11 = (int*)malloc((len1+1)*sizeof(int));
			clear(mass11, len1);
			Funct1(mass1, len1, mass, mass11, 1, b);
			Copy(mass11, len1,mass1);
			free(mass11);
			mass11 = (int*)malloc((len1+1)*sizeof(int));
			clear(mass11, len1);
			Funct1(mass2, len2, mass, mass11,1,b);
			Copy(mass11,len2,mass2);
			free(mass11);
		}
	}
	m=len1-len2;
	if (len1==len2)
	{
		m=1;
	}
	massdiv = (int*)malloc((m+3)*sizeof(int));
	clear(massdiv, m+2);
	if (len2>2)
	{
		massmul=(int*)malloc((len2+1)*sizeof(int));
		clear(massmul, len2+1);
		massmul[0]=mass2[0];
		for (int j=m; j>0; j--)
		{
			Copy(mass2,len2,massmul);
			divide(mass1,massmul,j,len2-1,massdiv,mass2,massr,b);
		}
	}
	else
	{
		if (mass2[1]==0)
		{
			printf("Error!");
			return 0;
		}
		massr[1] = dividenumb(mass1, massdiv, len1, mass2[1], b);
		if ((znak == '-') && (k2 == 1))
		{
			int massiv[2];
			massiv[0] = '-';
			massiv[1] = 1;
			massdiv[0] = numb;
			funsum(masssum, massdiv, m+2, massiv, 2, 2, b,name3, 2);
			int *massresult=(int*)malloc((len1+len2-1)*sizeof(int));
			clear(massresult, m+len2-1);
			Funct1(massdiv, m+1, mass2copy, massresult, 1, b);
			massresult[0] = '+';
			clear(massdiv, m);
			funsum (massdiv, massresult, m+len2, mass1copy, len1-1, 0, b, name3, 1);
			k2 = 4;
			free(massresult);
		}
	}
	massdiv[0] = numb;
	if (k2 == 0)
		Record (massdiv, m+1, name3, b);
	if (len2 > 2)
	{
		if (znak == '-')
		{
			int massiv[2];
			massiv[0] = '-';
			massiv[1] = 1;
			funsum(masssum, massdiv, len2, massiv, 2, 2, b, name3, 2);
			int *massresult=(int*)malloc((len1+len2-1)*sizeof(int));
			clear(massresult, len1+len2-1);
			Multiply (mass2copy, len2, massdiv, len2, massresult, len1+len2-1, b);
			massresult[0] = '+';
			clear (massdiv, len2);
			funsum (massdiv, massresult, len1+len2-1, mass1copy, len1, 0, b, name3, 1);
			k2 = 0;
			free(massresult);
		}
		else
		{
			free(massdiv);
			massdiv = (int*)malloc((len2)*sizeof(int));
			clear(massdiv, len2);
			k=0;
			k = dividenumb(mass1, massdiv, len2, d, b);//massdiv = остаток от деления
		}
	}
	if (k2 == 1)
	{
		if (b[1] == 0)
		{
			if ((len2 < 3) || (d == 1))
			{
				massr[0] = numb;
				Record(massr, len2, name3, b);
			}
			else
			{
				massdiv[0] = numb;
				Record(massdiv, len2, name3, b);
			}
		}
		else
		{
			if ((len2 < 3) || (d == 1))
			{
				clear(mass1, len1);
				Copy(massr, len2, mass1);
			}
			else
			{
				clear(mass1, len1);
				Copy(massdiv, len2, mass1);
			}
		}
	}
	free (massdiv);
	if (len2 > 2)
		free (massmul);
	free (mass1copy);
	free (mass2copy);
	free (massr);
	mass1[0] = znak;
	return mass1;
}
int deletez (int *mass1, unsigned int len1)
{
	int m = 0;
	for (int i = len1-1; i > 0; i--)
	{
		if (mass1[i] == 0)
		{
			m++;
		}
		else
			break;
	}
	return len1-m;
}
int compare (int *mass1, unsigned int len1, int *mass2)
{
	int min = 0;
	for (int i = len1-1; i > 0; i--)
	{
		if (mass1[i] != mass2[i])
		{
			if (mass1[i] < mass2[i])
			{
				min++;
				break;
			}
			else
				break;
		}
	}
	return min;
}
void funsum(int *mass, int *mass1, unsigned int len1, int *mass2, unsigned int len2, int k2, int *b, char name3[80], int zap)
{
	mass=(int*)malloc((len1+3)*sizeof(int));

	clear(mass, len1);
	Copy(mass1, len1-1, mass);
	if (k2 == 1)
		Invent (mass2, len2);
	if (k2 == 3)
		Invent (mass,len2);
	Summ (mass2, len2, mass,b);
	if (zap != 2)
		Record(mass, len1, name3,b);
	if (zap == 2)
	{
		clear (mass1, len1);
		Copy (mass,len1,mass1);
	}
	free(mass);
}
int divless(int *mass1, unsigned int len1, int *mass2, unsigned int len2,  char name3[80], int *b, int *masssum, int k2)
{
	int sd = 0;
	if (len1 == len2)
		sd = compare(mass1, len1, mass2);
	if ((len1 < len2) || (sd == 1))
	{
		if (k2 == 0)
		{
			free (mass1);
			len1 = 3;
			mass1 = (int*)malloc((len1)*sizeof(int));
			clear (mass1, len1);
			mass1[0] = '+';
			mass1[1] = 0;
			Record(mass1, len1, name3, b);
			printf("");
			return 1;
		}
		else
		{
			if (mass1[0]=='-')
			{
				funsum(masssum, mass2, len2+1, mass1, len1, 0, b, name3, 1);
				printf("");
				return 1;
			}
			else
			{
				Record(mass1, len1, name3, b);
				printf("");
				return 1;
			}
		}
	}
	return 0;
}
