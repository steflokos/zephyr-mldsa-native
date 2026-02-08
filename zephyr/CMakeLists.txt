# zephyr/CMakeLists.txt

zephyr_library()

zephyr_include_directories(../mldsa)
zephyr_library_include_directories(../mldsa)
zephyr_library_include_directories(..)

zephyr_library_sources(../mldsa/mldsa_native.c)

zephyr_library_sources(randombytes.c)

# Convert the Kconfig Choice to the Integer expected by C code
if(CONFIG_MLDSA_LEVEL_44)
    set(MLDSA_MODE_VAL 2)
elseif(CONFIG_MLDSA_LEVEL_65)
    set(MLDSA_MODE_VAL 3)
elseif(CONFIG_MLDSA_LEVEL_87)
    set(MLDSA_MODE_VAL 5)
else()
    set(MLDSA_MODE_VAL 5)
endif()


zephyr_library_compile_definitions(MLDSA_MODE=${MLDSA_MODE_VAL})