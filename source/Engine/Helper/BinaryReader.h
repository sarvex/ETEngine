#pragma once

class BinaryReader
{
public:
	BinaryReader(void);
	~BinaryReader(void);


	template<class T>
	T Read()
	{
		if (m_pReader == nullptr)
		{
			std::cout << 
				"[ERROR] BinaryReader doesn't exist!\nUnable to read binary data..."
				<< std::endl;
			return T();
		}

		T value;
		m_pReader->read((char*)&value, sizeof(T));
		return value;
	}

	std::string ReadString();
	std::string ReadLongString();
	std::string ReadNullString();

	int32 GetBufferPosition();
	bool SetBufferPosition(int32 pos);
	bool MoveBufferPosition(int32 move);
	bool Exists() const { return m_Exists; }

	void Open(std::string binaryFile);
	void Open(uint8* s, uint32 size);
	void Close();

private:

	bool m_Exists;
	std::istream* m_pReader;

private:
	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	BinaryReader(const BinaryReader& yRef);
	BinaryReader& operator=(const BinaryReader& yRef);
};

