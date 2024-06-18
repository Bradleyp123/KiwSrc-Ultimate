#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>

// Function to convert std::string to std::wstring
std::wstring StringToWString(const std::string& s) {
	int len;
	int slength = static_cast<int>(s.length()) + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	std::wstring r(len, L'\0');
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
	return r;
}

void RunProcessWithOutput(const std::wstring& exePath, const std::wstring& parameters) {
	// Combine the executable path and parameters
	std::wstring commandLine = exePath + L" " + parameters;

	// Structure to hold the process information
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	HANDLE g_hChildStd_OUT_Rd = NULL;
	HANDLE g_hChildStd_OUT_Wr = NULL;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags |= STARTF_USESTDHANDLES;

	ZeroMemory(&pi, sizeof(pi));

	// Set up the security attributes struct.
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	// Create a pipe for the child process's STDOUT.
	if (!CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &sa, 0)) {
		std::cerr << "Stdout pipe creation failed\n";
		return;
	}

	// Ensure the read handle to the pipe for STDOUT is not inherited.
	if (!SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0)) {
		std::cerr << "Stdout pipe set handle information failed\n";
		return;
	}

	// Set the handles for the process's standard output.
	si.hStdOutput = g_hChildStd_OUT_Wr;
	si.hStdError = g_hChildStd_OUT_Wr;

	// Create the child process.
	if (!CreateProcess(
		NULL,
		&commandLine[0],   // Command line
		NULL,              // Process handle not inheritable
		NULL,              // Thread handle not inheritable
		TRUE,              // Set handle inheritance to TRUE
		0,                 // No creation flags
		NULL,              // Use parent's environment block
		NULL,              // Use parent's starting directory 
		&si,               // Pointer to STARTUPINFO structure
		&pi)               // Pointer to PROCESS_INFORMATION structure
		) {
		std::cerr << "CreateProcess failed (" << GetLastError() << ")\n";
		return;
	}

	// Close handles to the stdout pipe no longer needed by the child process.
	CloseHandle(g_hChildStd_OUT_Wr);

	// Read output from the child process.
	DWORD dwRead;
	CHAR chBuf[4096];
	BOOL bSuccess = FALSE;
	HANDLE hParentStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (;;) {
		bSuccess = ReadFile(g_hChildStd_OUT_Rd, chBuf, 4096, &dwRead, NULL);
		if (!bSuccess || dwRead == 0) break;

		chBuf[dwRead] = '\0';
		std::cout << chBuf;
	}

	// Close handles.
	CloseHandle(g_hChildStd_OUT_Rd);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

std::wstring GetExecutablePath() {
	wchar_t buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
	return std::wstring(buffer).substr(0, pos);
}

int main() {
	std::wcout << L"Starting KiwiSrc SDK" << std::endl; // Display startup message

	std::wstring currentPath = GetExecutablePath();
	std::wstring exePath = currentPath + L"\\game.exe"; // Using "game.exe"
	std::wstring parameters = L"-game \"hlpc\\game\""; // Parameters for the executable
	RunProcessWithOutput(exePath, parameters);
	

		std::wcout << L"Starting Hammer Editor" << std::endl;

		std::wstring CurrentPath2 = GetExecutablePath();
		std::wstring exepath2 = CurrentPath2 + L"\bin\Hammer.exe";
		std::wstring parametershammer = L"-game \"hlpc\\game\""; // Parameters for the executable
		RunProcessWithOutput(exepath2, parametershammer);

		return 0;
}

