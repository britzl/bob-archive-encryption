#include <dmsdk/sdk.h>
#include <dmsdk/resource/resource_archive.h>

namespace dmSillyEncryption
{

	static dmResourceArchive::Result Decrypt(void* buffer, uint32_t buffer_len)
	{
		uint8_t* b = (uint8_t*)buffer;
		for (int i = 0; i < buffer_len; i++)
		{
			b[i] = b[i] - 11;
		}
		return dmResourceArchive::RESULT_OK;
	}

	static dmExtension::Result AppInitialize(dmExtension::AppParams* params)
	{
		dmResourceArchive::RegisterResourceDecryption(dmSillyEncryption::Decrypt);
		return dmExtension::RESULT_OK;
	}

	static dmExtension::Result Initialize(dmExtension::Params* params)
	{
		return dmExtension::RESULT_OK;
	}
}

DM_DECLARE_EXTENSION(SillyEncryption, "SillyEncryption", dmSillyEncryption::AppInitialize, 0, dmSillyEncryption::Initialize, 0, 0, 0);
