package com.dynamo.bob.archive;

import com.dynamo.bob.archive.ResourceEncryptionPlugin;


public class SillyEncryption extends ResourceEncryptionPlugin {

	@Override
	public byte[] encrypt(byte[] resource) throws Exception {
		for (int i = 0; i < resource.length; i++) {
			resource[i] = (byte)(resource[i] + 11);
		}
		return resource;
	}
}