#include <assert.h>
#include <stdint.h>
#include <stddef.h>

#define byte4 0xFF, 0xFF, 0xFF, 0xFF
#define byte8 byte4, byte4
#define byte16 byte8, byte8
#define byte32 byte16, byte16
#define byte64 byte32, byte32
#define byte128 byte64, byte64
#define byte256 byte128, byte128
#define byte512 byte256, byte256
#define byte1K byte512, byte512
#define byte2K byte1K, byte1K
#define byte4K byte2K, byte2K

#define EXAM_BUFFER_CONTENT byte4K

constexpr static int ExamModeBufferSize = 4*1024;

uint32_t staticStorageArea = {0};

class KernelHeader {
    public:
    constexpr KernelHeader() :
        m_header(Magic),
        m_version{"0.0.0"},
        m_patchLevel{"zeta"},
        m_footer(Magic) { }
    const char * version() const {
        assert(m_header == Magic);
        assert(m_footer == Magic);
        return m_version;
    }
    const char * patchLevel() const {
        assert(m_header == Magic);
        assert(m_footer == Magic);
        return m_patchLevel;
    }
    private:
        constexpr static uint32_t Magic = 0xDEC00DF0;
        uint32_t m_header;
        const char m_version[8];
        const char m_patchLevel[8];
        uint32_t m_footer;
};

class UserlandHeader {
public:
  constexpr UserlandHeader():
    m_header(Magic),
    m_expectedEpsilonVersion{"0.0.1"},
    m_storageAddressRAM(0x20000AE8),
    m_storageSizeRAM(0x0000EA60),
    m_externalAppsFlashStart(0xFFFFFFFF),
    m_externalAppsFlashEnd(0xFFFFFFFF),
    m_externalAppsRAMStart(0xFFFFFFFF),
    m_externalAppsRAMEnd(0xFFFFFFFF),
    m_footer(Magic),
    m_omegaMagicHeader(OmegaMagic),
    m_omegaVersion{"0.0.2"},
    m_username{"Ayabusa"},

    m_omegaMagicFooter(OmegaMagic),
    m_upsilonMagicHeader(UpsilonMagic),
    m_UpsilonVersion{"0.0.3"},
    m_osType(OSType),
    m_upsilonMagicFooter(UpsilonMagic) { }

  const char * omegaVersion() const {
    assert(m_header == Magic);
    assert(m_footer == Magic);
    assert(m_omegaMagicHeader == OmegaMagic);
    assert(m_omegaMagicFooter == OmegaMagic);
    return m_omegaVersion;
  }
  const char * upsilonVersion() const {
    assert(m_header == Magic);
    assert(m_footer == Magic);
    assert(m_omegaMagicHeader == OmegaMagic);
    assert(m_omegaMagicFooter == OmegaMagic);
    return m_UpsilonVersion;
  }
  const volatile char * username() const volatile {
    assert(m_header == Magic);
    assert(m_footer == Magic);
    assert(m_omegaMagicHeader == OmegaMagic);
    assert(m_omegaMagicFooter == OmegaMagic);
    return m_username;
  }
  const void * storage_address() const {
    return &staticStorageArea;
  }

  private:
  constexpr static uint32_t Magic = 0xDEC0EDFE; // FEEDCODE in hex editor
  constexpr static uint32_t OmegaMagic = 0xEFBEADDE; // DEADBEEF in hex editor
  constexpr static uint32_t UpsilonMagic = 0x55707369; // Upsi (reverse) in hex editor (ASCII)
  constexpr static uint32_t OSType = 0x79827178;
  uint32_t m_header;
  const char m_expectedEpsilonVersion[8];
  uint32_t m_storageAddressRAM;
  uint32_t m_storageSizeRAM;
  /* We store the range addresses of external apps memory because storing the
   * size is complicated due to c++11 constexpr. */
  uint32_t m_externalAppsFlashStart;
  uint32_t m_externalAppsFlashEnd;
  uint32_t m_externalAppsRAMStart;
  uint32_t m_externalAppsRAMEnd;
  uint32_t m_footer;
  uint32_t m_omegaMagicHeader;
  const char m_omegaVersion[16];
  const volatile char m_username[16];
  uint32_t m_omegaMagicFooter;
  uint32_t m_upsilonMagicHeader;
  const char m_UpsilonVersion[16];
  uint32_t m_osType;
  uint32_t m_upsilonMagicFooter;
};

// kernel header defined in linker
const KernelHeader __attribute__((section(".kernel_header"), used)) k_kernelHeader;
// userland header defined in linker
const UserlandHeader __attribute__((section(".userland_header"), used)) k_userlandHeader;

// Exam mode defined in linker
char ones[ExamModeBufferSize]
  __attribute__((section(".exam_mode_buffer")))
  __attribute__((used))
= {EXAM_BUFFER_CONTENT};