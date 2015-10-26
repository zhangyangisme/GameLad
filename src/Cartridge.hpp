#pragma once

class Cartridge : public IMemoryUnit
{
public:
    Cartridge();
    ~Cartridge();

    bool LoadROM(std::string path);

    // IMemoryUnit
    byte ReadByte(const ushort& address);
    bool WriteByte(const ushort& address, const byte val);

private:
    bool LoadMBC(__int64 actualSize);

private:
    std::unique_ptr<byte> m_ROM;
    std::unique_ptr<byte> m_RAM;
    std::unique_ptr<IMemoryUnit> m_MBC;
};
