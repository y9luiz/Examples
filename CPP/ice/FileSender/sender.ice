#pragma once
module Demo
{
	sequence<byte> Data;

	struct File
	{
		string filename;
		Data data;
	}

	interface Sender
	{
		void sendFile(File file);
	}
	
}