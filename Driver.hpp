#include <Windows.h>
#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <mutex>
#include <TlHelp32.h>
#include "Driver/driver.h"

static std::uint32_t pId = 0;
uint64_t game_assembly, unity_player;

template <typename Type>
Type ReadChain(uint64_t address, std::vector<uint64_t> chain) {
	uint64_t current = address;
	for (int i = 0; i < chain.size() - 1; i++) {
		current = Driver.Read<uint64_t>(current + chain[i]);
	}
	return Driver.Read<Type>(current + chain[chain.size() - 1]);
}

std::wstring ReadUnicode(uint64_t address)
{
	wchar_t buffer[1024 * sizeof(wchar_t)];

	Driver.ReadArr(address, &buffer, 1024 * sizeof(wchar_t));

	return std::wstring(buffer);
}

std::wstring read_wstring(uintptr_t String_address, SIZE_T size)
{
	const auto buffer = std::make_unique<wchar_t[]>(size);
	Driver.ReadArr(String_address, (uint8_t*)buffer.get(), size * 2);
	return std::wstring(buffer.get());
}

std::string ReadNative(uint64_t address)
{
	char buffer[1024];

	Driver.ReadArr(Driver.Read<uint64_t>(address), &buffer, 1024);

	return std::string(buffer);
}