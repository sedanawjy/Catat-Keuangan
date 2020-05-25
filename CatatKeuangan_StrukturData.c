/*Program ini dibuat oleh:

	 Teknik Informatika
	Universitas Udayana
	
Nama		: I Putu Sedana Wijaya
NIM			: 1808561034
E-mail		: sedanawjy@gmail.com
Linkedin	: https://www.linkedin.com/in/i-putu-sedana-wijaya-0109a7188

*/
#include<stdio.h>
#include<string.h>
int banding, i,t,j;
int pilihan, tambah, tambah_akun[2], q_utama, q_akun, q_out, q_in, q[2];
int plus_out=0,plus_in=0,total_in=0,total_out=0, date[4];
	
struct data{
	char akun[20];
	int nilai;
	int jumlah;
	struct data *next;
	struct data *prev;
}*kepala_out, *ekor_out, *tambah_out, *cek_out, *kepala_in, *ekor_in, *tambah_in, *cek_in;

struct data_utama{
	int tgl;
	int bln;
	int thn;
	int angka;
	char komentar[20];
	struct data_utama *next;
	struct data_utama *prev;
}*head_out, *tail_out, *baru_out,*head_in, *tail_in, *baru_in;

int cek_tgl(int a,int b,int c){
	t=0;
	if(c % 4 == 0 && b == 2 && a > 29){
		printf("Tanggal Anda Salah!\n");
	}else if(c % 4 > 0 && b == 2 && a > 28){
		printf("Tanggal Anda Salah!\n");
	}else if(b < 8 && b % 2 == 1 && a > 31){
		printf("Tanggal Anda Salah!\n");				
	}else if(b > 7 && b % 2 == 0 && a > 31){
		printf("Tanggal Anda Salah!\n");				
	}else if(b < 8 && b != 2 && b % 2 == 0 && a > 30){
		printf("Tanggal Anda Salah!\n");	
	}else if(b > 7 && b % 2 == 1 && a > 30){
		printf("Tanggal Anda Salah!\n");				
	}else if(a <= 0 || a > 31 ){
		if(b <= 0 || b > 12){
			if(c <= 1999 || c >= 3000){
				printf("Tanggal Anda Salah!\n");				
			}else if(c > 1999 || c < 3000){
				printf("Tanggal Anda Salah!\n");				
			}
		}else if(b > 0 || b < 13){
			if(c <= 1999 || c >= 3000){
				printf("Tanggal Anda Salah!\n");				
			}else if(c > 1999 || c < 3000){
				printf("Tanggal Anda Salah!\n");				
			}
		}
	}else if(a > 0 || a < 32){
		if(b <= 0 || b > 12){
			if(c <= 1999 || c >= 3000){
				printf("Tanggal Anda Salah!\n");				
			}else if(c > 1999 || c < 3000){
				printf("Tanggal Anda Salah!\n");				
			}
		}else if(b > 0 || b < 13){
			if(c <= 1999 || c >= 3000){
				printf("Tanggal Anda Salah!\n");				
			}else if(c > 1999 || c < 3000){
				t++;
			}
		}
	}
	return t;
}
/////////////////////////////////////////////// AKUN PENGELUARAN ////////////////////////////////////////////////////////////////////
void akun1(){
	//plus berguna untuk menambah jumlah akun yang ada
	plus_out++;
	tambah_out = (struct data*)malloc(sizeof(struct data));
	printf("Nama Akun: ");	fflush(stdin); gets(tambah_out->akun);
	if(kepala_out == NULL){
		kepala_out = tambah_out;
		ekor_out = tambah_out;
		tambah_out->nilai = 0;
		tambah_out->jumlah = plus_out;
		printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun %s sudah ditambahkan!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n", tambah_out->akun);	
	}else{
		//tahap cek apakah input akun sudah ada
		ekor_out->next = tambah_out;
		cek_out = kepala_out;
		banding = 1;
		for(i = 1; i < plus_out ; i++){
			banding = strcmp(cek_out->akun, tambah_out->akun);
			if(banding == 0){
				break;
			}
			cek_out = cek_out->next;
		}
		if(banding == 0){
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun anda sudah ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
			ekor_out->next = NULL;
			free(tambah_out);
			plus_out--;
		}else if(banding > 0 || banding < 0){
			//nilai awal akun = 0
			tambah_out->nilai = 0;
			//masukan akun ke- berapa
			tambah_out->jumlah = plus_out;	
			//double linked list
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun %s sudah ditambahkan!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n", tambah_out->akun);
			tambah_out->prev = ekor_out;
			ekor_out = tambah_out;
		}
	}
};
/////////////////////////////////////////////// AKUN PEMASUKAN ////////////////////////////////////////////////////////////////////
void akun2(){
	//plus berguna untuk menambah jumlah akun yang ada
	plus_in++;
	tambah_in = (struct data*)malloc(sizeof(struct data));
	printf("Nama Akun: ");	fflush(stdin); gets(tambah_in->akun);								
	if(kepala_in == NULL){
		kepala_in = tambah_in;
		ekor_in = tambah_in;
		tambah_in->nilai = 0;
		tambah_in->jumlah = plus_in;	
		printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun %s sudah ditambahkan!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n", tambah_in->akun);	
	}else{
		//tahap cek apakah input akun sudah ada
		ekor_in->next = tambah_in;
		cek_in = kepala_in;
		banding = 1;
		for(i = 1; i < plus_in ; i++){
			banding = strcmp(cek_in->akun, tambah_in->akun);
			if(banding == 0){
				break;
			}
			cek_in = cek_in->next;
		}
		//jika sudah ada (banding=0) maka hapus akun
		if(banding == 0){
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun anda sudah ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
			ekor_in->next = NULL;
			free(tambah_in);
			plus_in--;
		}else if(banding > 0 || banding < 0){
			//nilai awal akun = 0
			tambah_in->nilai = 0;
			//masukan akun ke- berapa
			tambah_in->jumlah = plus_in;	
			//double linked list
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun %s sudah ditambahkan!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n", tambah_in->akun);
			tambah_in->prev = ekor_in;
			ekor_in = tambah_in;
		}	
	}
};

	void view_akun1(){
		if(plus_out==0){
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}else{
			tambah_out=kepala_out;
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tLihat Akun Pengeluaran\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tNo.\tNama Akun\tSaldo\n");
			i=0;										
			while(tambah_out!=NULL){
				i+=1;
				printf("\t%d.\t%s\t\tRp. %d,-\n",i,tambah_out->akun,tambah_out->nilai);
				tambah_out = tambah_out->next;
			}
		}
	};

	void view_akun2(){
		if(plus_in==0){
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}else{
			tambah_in = kepala_in;
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tLihat Akun Pemasukan\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tNo.\tNama Akun\tSaldo\n");
			i=0;
			while(tambah_in!=NULL){
				i+=1;
				printf("\t%d.\t%s\t\tRp. %d,-\n",i,tambah_in->akun,tambah_in->nilai);
				tambah_in = tambah_in->next;
			}										
		}	
	};

	void view_akun3(){
		if(plus_out==0){
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}else{
			tambah_out=kepala_out;
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tLihat Akun Pengeluaran\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tNo.\tNama Akun\tSaldo\n");
			i=0;										
			while(tambah_out!=NULL){
				i+=1;
				printf("\t%d.\t%s\t\tRp. %d,-\n",i,tambah_out->akun,tambah_out->nilai);
				tambah_out = tambah_out->next;
			}
		}	
		if(plus_in==0){
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}else{
			tambah_in = kepala_in;
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tLihat Akun Pemasukan\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tNo.\tNama Akun\tSaldo\n");
			i=0;
			while(tambah_in!=NULL){
				i+=1;
				printf("\t%d.\t%s\t\tRp. %d,-\n",i,tambah_in->akun,tambah_in->nilai);
				tambah_in = tambah_in->next;
			}										
		}
		system("pause");
	};
/////////////////////////////////////////////////// PENGELUARAN ///////////////////////////////////////////////////////////////////////
void pengeluaran(){
	if(plus_out==0){
		printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun Belum Dibuat!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
	}else{
		baru_out = (struct data_utama*)malloc(sizeof(struct data_utama));
		if(head_out == NULL){
			head_out = baru_out;
			tail_out = baru_out;	
		}else{
			tail_out->next = baru_out;
			baru_out->prev = tail_out;
			tail_out = baru_out;
		}
		printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tNo.\tNama Akun\tSaldo\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		tambah_out = kepala_out;
		i=0;
		while(tambah_out!=NULL){
			i+=1;
			printf("\t%d.\t%s\t\tRp. %d,-\n",i,tambah_out->akun,tambah_out->nilai);
			tambah_out = tambah_out->next;
		}
		printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\nPilih nomor Akun Pengeluaran: "); scanf("%d",&i);
		printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		tambah_out = kepala_out;				
		j=0;
		while(tambah_out!=NULL){
			if(tambah_out->jumlah == i){
				j++;
				break;
			}
			tambah_out = tambah_out->next;
		}
		if(j>0){
			printf("Jumlah pengeluaran: "); scanf("%d",&tambah);
			baru_out->angka = tambah;
			tambah_out->nilai = tambah_out->nilai + tambah;
			strcpy(baru_out->komentar, tambah_out->akun);
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPengeluaran untuk %s sebesar Rp. %d telah diinput\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n",baru_out->komentar,tambah);	
			do{
				printf("Tanggal\t: "); scanf("%d", &baru_out->tgl);
				printf("Bulan\t: "); scanf("%d", &baru_out->bln);
				printf("Tahun\t: "); scanf("%d", &baru_out->thn);
				cek_tgl(baru_out->tgl, baru_out->bln, baru_out->thn);
			}while(t==0);				
		}
		else{
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}	
	}
};
////////////////////////////////////////////////// PEMASUKAN ////////////////////////////////////////////////////////////////////////////
void pemasukan(){
	if(plus_in==0){
		printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun Belum Dibuat!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
	}else{
		baru_in = (struct data_utama*)malloc(sizeof(struct data_utama));
		if(head_in == NULL){
			head_in = baru_in;
			tail_in = baru_in;	
		}else{
			tail_in->next = baru_in;
			baru_in->prev = tail_in;
			tail_in = baru_in;
		}
		printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tNo.\tNama Akun\tSaldo\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		tambah_in = kepala_in;
		i=0;
		while(tambah_in!=NULL){
			i+=1;
			printf("\t%d.\t%s\t\tRp. %d,-\n", i, tambah_in->akun, tambah_in->nilai);
			tambah_in = tambah_in->next;
		}
		printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\nPilih nomor Akun Pemasukan: "); scanf("%d",&i);
		printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		tambah_in = kepala_in;
		j=0;
		while(tambah_in!=NULL){
			if(tambah_in->jumlah == i){
				j++;
				break;
			}
			tambah_in = tambah_in->next;
		}
		if(j>0){
			printf("Jumlah pengeluaran: "); scanf("%d",&tambah);
			baru_in->angka = tambah;
			tambah_in->nilai = tambah_in->nilai + tambah;
			strcpy(baru_in->komentar, tambah_in->akun);
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPengeluaran untuk %s sebesar Rp. %d telah diinput\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n", baru_in->komentar, tambah);								
			do{
				printf("Tanggal\t: "); scanf("%d", &baru_in->tgl);
				printf("Bulan\t: "); scanf("%d", &baru_in->bln);
				printf("Tahun\t: "); scanf("%d", &baru_in->thn);
				cek_tgl(baru_in->tgl, baru_in->bln, baru_in->thn);
			}while(t==0);							
		}
		else{
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAkun Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}
	}
};

	void view_pengeluaran(){
		if(head_out!=NULL){
			baru_out = head_out;
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tTanggal\t\tPengeluaran\t\tDeskripsi\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
			while(baru_out != tail_out){
				printf("\t%d/%d/%d\tRp. %d,-\t\t%s\n", baru_out->tgl, baru_out->bln, baru_out->thn, baru_out->angka, baru_out->komentar);		
				baru_out = baru_out->next;
			}
			printf("\t%d/%d/%d\tRp. %d,-\t\t%s\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n", baru_out->tgl, baru_out->bln, baru_out->thn, baru_out->angka, baru_out->komentar);
		}else{
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tData Pengeluaran Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}
	};
	
	void view_pemasukan(){
		if(head_in!=NULL){
			baru_in = head_in;
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tTanggal\t\tPemasukan\t\tDeskripsi\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
			while(baru_in != tail_in){
				printf("\t%d/%d/%d\tRp. %d,-\t\t%s\n",baru_in->tgl, baru_in->bln, baru_in->thn, baru_in->angka, baru_in->komentar);
				baru_in = baru_in->next;
			}
			printf("\t%d/%d/%d\tRp. %d,-\t\t%s\n",baru_in->tgl, baru_in->bln, baru_in->thn, baru_in->angka, baru_in->komentar);		
		}else{
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tData Pemasukan Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}		
	};
	
	void view_data(){
		if(head_out == NULL){
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPENGELUARAN ANDA BELUM ADA!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}else{
			baru_out = head_out;
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\t\tPENGELUARAN ANDA\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tTanggal\t\tPengeluaran\t\tDeskripsi\n");
			while(baru_out != tail_out){
				printf("\t%d/%d/%d\tRp. %d,-\t\t%s\n", baru_out->tgl, baru_out->bln, baru_out->thn, baru_out->angka, baru_out->komentar);		
				total_out = total_out+baru_out->angka;
				baru_out = baru_out->next;
			}
			total_out = total_out+baru_out->angka;
			printf("\t%d/%d/%d\tRp. %d,-\t\t%s\n", baru_out->tgl, baru_out->bln, baru_out->thn, baru_out->angka, baru_out->komentar);
		}
		if(head_in == NULL){
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPEMASUKAN ANDA BELUM ADA!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
		}else{
			baru_in = head_in;
			printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\t\tPEMASUKAN ANDA\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tTanggal\t\tPemasukan\t\tDeskripsi\n");
			while(baru_in != tail_in){
				printf("\t%d/%d/%d\tRp. %d,-\t\t%s\n", baru_in->tgl, baru_in->bln, baru_in->thn, baru_in->angka, baru_in->komentar);
				total_in = total_in+baru_in->angka;
				baru_in = baru_in->next;
			}
			total_in = total_in+baru_in->angka;
			printf("\t%d/%d/%d\tRp. %d,-\t\t%s\n",baru_in->tgl, baru_in->bln, baru_in->thn, baru_in->angka, baru_in->komentar);		
		}
		if(total_in > total_out){
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAnda HEMAT,tingkatkan lagi ya :)\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");					
		}else if(total_in < total_out){
			printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tAnda BOROS,lebih hemat lagi ya :)\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");						
		}		
	};

void cari_data(){
	printf("\tMenuju ke MENU CARI...\n");
	system("pause");
	do{
		date[3]=0;
		system("cls");
		printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\t\tMENU CARI\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\t\t1. Pengeluaran\n\t\t2. Pemasukan\n\t\t3. Ke Menu Utama\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");						
		printf("\tPilihan: "); scanf("%d", &pilihan);
		switch(pilihan){
			case 1:
				if(head_out!=NULL){
					printf("Cari tanggal: "); scanf("%d",&date[0]);
					printf("Cari bulan: "); scanf("%d",&date[1]);
					printf("Cari tahun: "); scanf("%d",&date[2]);
					baru_out = head_out;
					i=0;
					while(baru_out != tail_out){
						if(baru_out->tgl == date[0] && baru_out->bln == date[1] && baru_out->thn == date[2]){
							printf("\n\n\tTanggal %d/%d/%d\tRp. %d\t/t%s", baru_out->tgl, baru_out->bln, baru_out->thn, baru_out->angka, baru_out->komentar);
							i++;
						}
						baru_out = baru_out->next;
					}
					if(baru_out->tgl == date[0] && baru_out->bln == date[1] && baru_out->thn == date[2]){
						printf("\nTanggal %d/%d/%d\tRp. %d\t%s\n", baru_out->tgl, baru_out->bln, baru_out->thn, baru_out->angka, baru_out->komentar);
						i++;
					}
					if(i==0){
						printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\nPengeluaran yang Dicari Tidak Ditemukan\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
					}
				}else{
					printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tData Pengeluaran Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
				}						
				break;
							
			case 2:
				if(head_out!=NULL){
					printf("Cari tanggal: "); scanf("%d",&date[0]);
					printf("Cari bulan: "); scanf("%d",&date[1]);
					printf("Cari tahun: "); scanf("%d",&date[2]);
					baru_in = head_in;
					i=0;
					while(baru_in != tail_in){
						if(baru_in->tgl == date[0] && baru_in->bln == date[1] && baru_in->thn == date[2]){
							printf("\nTanggal %d/%d/%d\tRp. %d\t%s\n", baru_in->tgl, baru_in->bln, baru_in->thn, baru_in->angka, baru_in->komentar);
							i++;
						}
						baru_in = baru_in->next;
					}
					if(baru_in->tgl == date[0] && baru_in->bln == date[1] && baru_in->thn == date[2]){
						printf("\nTanggal %d/%d/%d\tRp. %d\t%s\n", baru_in->tgl, baru_in->bln, baru_in->thn, baru_in->angka, baru_in->komentar);
						i++;
					}
					if(i==0){
						printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\nPemasukan yang Dicari Tidak Ditemukan\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
					}
				}else{
					printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tData Pemasukan Tidak Tersedia!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
				}						
				break;
						
			case 3:
				date[3]++;
				break;
						
			default:
				printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPilihan Anda tidak ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
				break;
		}
		system("pause");
	}while(date[3]==0);	
};

int main(){
	tambah_out = NULL; tambah_in = NULL; cek_out = NULL; cek_in = NULL; 
	kepala_out = NULL; ekor_out = NULL;	kepala_in = NULL; ekor_in = NULL;
	head_out = NULL; tail_out = NULL; baru_out = NULL;
	head_in = NULL; tail_in = NULL; baru_in = NULL;
	char cari[20];
   	printf("\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n\t³\t     Program Catat Keuangan\t\t³\n\t³\t        Selamat Datang!\t\t\t³\n\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	printf("\n\t\t    Just For Your Information\n\n1.\tGunakan Akun Sebagai Deskripsi\n\tuntuk Pengeluaran dan Pemasukan Anda pada menu 1\n\n2.\tSegala pengeluaran dan pemasukan \n\tAnda dapat dicatat pada menu 2 dan 3\n\n3.\tDari melihat aktifitas keuangan pada menu 4, \n\tAnda bisa mengatur keuangan kedepannya\n\n3.\tCari data pengeluaran dan pemasukan\n\tAnda pada menu 4 (Cari Data)\n\n");
	system("pause");
	do{
		q_utama=0;
		system("cls");
		printf("\n\t\t\tMENU UTAMA\n\t\t      CATAT KEUANGAN\nÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n³\t\t1. Akun Keuangan\t\t\t³\n³\t\t2. Pengeluaran Keuangan\t\t\t³\n");
		printf("³\t\t3. Pemasukan Keuangan\t\t\t³\n³\t\t4. Lihat dan Cari Data Keuangan\t\t³\n³\t\t5. Keluar Program\t\t\t³\nÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
		printf("\t\tMasukan Pilihan: ");	scanf("%d",&pilihan);
		switch(pilihan){		
			case 1: // MENU AKUN
				do{
					q_akun=0;
					system("cls");				
					printf("\n\t\t\tMENU AKUN\n\t\t      CATAT KEUANGAN\nÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n³\t\t1. Akun Pengeluaran\t\t\t³\n³\t\t2. Akun Pemasukan\t\t\t³\n");
					printf("³\t\t3. Lihat Semua Akun\t\t\t³\n³\t\t4. Ke Menu Utama\t\t\t³\nÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
					printf("\t\tMasukan Pilihan: ");	scanf("%d",&pilihan);				
					switch(pilihan){
						case 1:	//AKUN PENGELUARAN
							do{
								q[0]=0;
								system("cls");
								printf("\n\t\t     AKUN PENGELUARAN\n\t\t      CATAT KEUANGAN\nÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n³\t\t1. Tambah Akun Pengeluaran\t\t³\n³\t\t2. Lihat Akun Pengeluaran\t\t³\n");
								printf("³\t\t3. Kembali ke Menu Akun\t\t\t³\n³\t\t4. Ke Menu Utama\t\t\t³\nÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
								printf("\t\tMasukan Pilihan: ");	scanf("%d",&pilihan);											switch(pilihan){
									case 1:
										akun1();
										break;
										
									case 2:
										view_akun1();
										break;
										
									case 3:
										q[0]++;
										break;
									
									case 4:
										q[0]++;
										q_akun++;
										break;
										
									default:
										printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPilihan Anda tidak ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");	
										break;
								}					
								system("pause");
							}while(q[0]==0); //akun pengeluaran
							break;
						
						case 2: //AKUN PEMASUKAN
							do{
								q[1]=0;
								system("cls");
								printf("\n\t\t      AKUN PEMASUKAN\n\t\t      CATAT KEUANGAN\nÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n³\t\t1. Tambah Akun Pemasukan\t\t³\n³\t\t2. Lihat Akun Pemasukan\t\t\t³\n");
								printf("³\t\t3. Kembali ke Menu Akun\t\t\t³\n³\t\t4. Ke Menu Utama\t\t\t³\nÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
								printf("\t\tMasukan Pilihan: ");	scanf("%d",&pilihan);						
								switch(pilihan){
									case 1:
										akun2();
										break;
										
									case 2:
										view_akun2();
										break;
										
									case 3:
										q[1]++;
										break;
										
									case 4:
										q[1]++;
										q_akun++;
										break;										
										
									default:
										printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPilihan Anda tidak ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
										break;
								}					
								system("pause");
							}while(q[1]==0); //akun pengeluaran						
							break;
						
						case 3: // LIHAT ALL AKUN
							view_akun3();
							break;
							
						case 4:
							q_akun++;
							break;
							
						default:
							printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPilihan Anda tidak ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
							break;
					} //tutup menu akun
				}while(q_akun==0);
				break;
				
			case 2: //MENU PENGELUARAN
				do{
					q_out=0;
					system("cls");
					printf("\n\t\t     MENU PENGELUARAN\n\t\t      CATAT KEUANGAN\nÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n³\t\t1. Tambah Pengeluaran\t\t\t³\n³\t\t2. Lihat Pengeluaran\t\t\t³\n");
					printf("³\t\t3. Ke Menu Utama\t\t\t³\nÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\t\tMasukan Pilihan: ");	scanf("%d",&pilihan);
					switch(pilihan){
						case 1:
							pengeluaran();
							break;
							
						case 2:
							view_pengeluaran();
							break;
							
						case 3:
							q_out++;
							break;
							
						default:
							printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPilihan Anda tidak ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
							break;
					} //tutup menu pengeluaran
					system("pause");
				}while(q_out==0);
				break;
			
			case 3: //MENU PEMASUKAN
				do{
					q_out=0;
					system("cls");
					printf("\n\t\t     MENU PEMASUKAN\n\t\t      CATAT KEUANGAN\nÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n³\t\t1. Tambah Pemasukan\t\t\t³\n³\t\t2. Lihat Pemasukan\t\t\t³\n");
					printf("³\t\t3. Ke Menu Utama\t\t\t³\nÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\t\tMasukan Pilihan: ");	scanf("%d",&pilihan);
					switch(pilihan){
						case 1:
							pemasukan();
							break;
							
						case 2:
							view_pemasukan();
							break;
							
						case 3:
							q_in++;
							break;
							
						default:
							printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPilihan Anda tidak ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
							break;
					} //tutup menu pemasukan
					system("pause");
				}while(q_in==0);	
				break;
				
			case 4: //lihat data
				view_data();
				cari_data();
				break;
				
			case 5:
				q_utama++;
				break;
				
			default:
				printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\tPilihan Anda tidak ada!\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n");
				system("pause");
				break;
		}
	}while(q_utama==0);		
	return 0;
}
