#include <iostream>
#include "Folder.h"
#include "File.h"
#include "FileSystemElement.h"
using namespace std;

int main()
{
	Folder* f1 = new Folder((char*)"folder1");
	Folder* f2 = new Folder((char*)"folder2");
	Folder* f3 = new Folder((char*)"folder3");
	Folder* f4 = new Folder((char*)"folder4");
	Folder* f5 = new Folder((char*)"folder5");
	Folder* f6 = new Folder((char*)"folder6");
	File* fajl1 = new File((char*)"fajl1", (char*)"exe");
	File* fajl2 = new File((char*)"fajl2", (char*)"txt");

	f1->dodaj(f2);
	f2->dodaj(f3);
	
	f3->dodaj(f4);
	f3->dodaj(f5);
	f3->dodaj(f6);

	f4->dodaj(fajl1);
	f4->dodaj(fajl2);

	cout << "sadrzaj foldera 3:\n";
	f3->PrintList();
	cout << endl;

	cout << "uklonjen folder5, sadrzaj foldera 3:\n";
	f3->ukloni(2);
	f3->PrintList();
	cout << endl;

	cout << "dodan fajl u folder 2, sadrzaj foldera 2:\n";
	f2->dodaj(new File((char*)"dodan", (char*)"jpg"));
	f2->PrintList();
	cout << endl << endl;

	cout << "svi sa istim roditeljem kao fajl2:\n";
	fajl2->PrintList();

	return 0;
}