#include <dmsdk/sdk.h>
#include <dmsdk/resource/resource_archive.h>


static dmResourceArchive::Result Decrypt(void* buffer, uint32_t buffer_len)
{
	dmLogInfo("Decrypt()");
	uint8_t* b = (uint8_t*)buffer;
	for (int i = 0; i < buffer_len; i++)
	{
		b[i] = b[i] - 11;
	}
	return dmResourceArchive::RESULT_OK;
}

static dmExtension::Result AppInitializeSillyEncryption(dmExtension::AppParams* params)
{
	dmLogInfo("AppInitializeSillyEncryption");
	dmResourceArchive::RegisterResourceDecryption(Decrypt);

	return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(SillyEncryption, "SillyEncryption", AppInitializeSillyEncryption, 0, 0, 0, 0, 0);
