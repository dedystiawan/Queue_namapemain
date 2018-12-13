#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

typedef struct data{
	string namapemain;
	string posisi;
	int nopung;
}dData;

class simpul
{
	public :
		dData datapemain;
		simpul* pBerikutnya;
		
		
		simpul(string np,string p, int nop)
		{
			datapemain.namapemain = np;
			datapemain.posisi = p;
			datapemain.nopung = nop;
			pBerikutnya = NULL;
		}
		
		void tampilSimpul()
		{
			cout << datapemain.nopung << "--->" << datapemain.namapemain << "--->" << datapemain.posisi<<endl;
		}
};

class linkedlist
{
	private :
		simpul* pPertama;
		simpul* pAkhir;
	
	public :
		linkedlist() : pPertama(NULL)
		{}
		
		~linkedlist()
		{
			simpul* pSekarang = pPertama;
			while(pSekarang!=NULL)
			{
				simpul* pLama = pSekarang;
				pSekarang = pSekarang->pBerikutnya;
				delete pLama;
			}
		}
		
		bool apaKosong()
		{
			return (pPertama==NULL);
		}
		
		void sisipAkhir(string np, string p, int nop)
		{
			simpul* pSimpulBaru = new simpul(np,p,nop);
			if(apaKosong())
			{
				pPertama = pSimpulBaru;
			}
			else
			{
				pAkhir->pBerikutnya=pSimpulBaru;
			}
			pAkhir=pSimpulBaru;
		}
		
		void hapusPertama()
		{
			simpul* pTemp = pPertama;
			pPertama = pPertama->pBerikutnya;
			delete pTemp;
		}
		
		void tampilSenarai()
		{
			simpul* pSekarang = pPertama;
			if(pSekarang==NULL)
			{
				cout << "STACK KOSONG!!!";
			}
			while(pSekarang!=NULL)
			{
				pSekarang->tampilSimpul();
				pSekarang = pSekarang->pBerikutnya;
			}
			cout << endl;
		}
};

class queuelist
{
	private :
		linkedlist* pSenarai;
	
	public :
		queuelist()
		{
			pSenarai = new linkedlist;
		}
		
		~queuelist()
		{
			delete pSenarai;
		}
		
		void push(string np, string p, int nop)
		{
			pSenarai->sisipAkhir(np,p,nop);
		}
		
		void pop()
		{
			pSenarai->hapusPertama();	
		}
		
		bool apaKosong()
		{
			return (pSenarai->apaKosong());
		}
		
		void tampilTumpukan()
		{
			pSenarai->tampilSenarai();
		}
};

int main()
{
	queuelist queue;
	int pilihan, nomor;
	string nama, posisimain;
	do 
	{
		cout << "\n=====================================================" << endl;
		cout << "Queue Menggunakan Linked List (Data Pemain Sepakbola)" << endl << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Tampil Data" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Masukkan Pilihan Anda : ";
		cin >> pilihan;
		cout << "=====================================================" << endl;
	
		switch(pilihan)
		{
			case 1 :
				cout << "\nMasukkan Nomer Punggung Pemain : "; cin >> nomor;
				cin.ignore(256,'\n');
				cout << "Masukkan Nama Pemain : "; getline(cin,nama);
				cout << "Masukkan Posisi Pemain : "; getline(cin,posisimain);
				queue.push(nama,posisimain,nomor);
				break;
				
			case 2 :
				queue.pop();
				break;
			
			case 3 :
				queue.tampilTumpukan();
				break;
				
			case 4 :
				exit(0);
				break;
				
			default :
				cout << "pilihan yang anda masukkan salah!!!"<<endl;
		}
	} while (true);
	getch();
	return 0;
}
