# zephyr/CMakeLists.txt

zephyr_library()

zephyr_include_directories(../mldsa)
zephyr_library_include_directories(../mldsa)
zephyr_library_include_directories(..)

zephyr_library_sources(../mldsa/mldsa_native.c)

zephyr_library_sources(randombytes.c)

# Convert the Kconfig Choice to the Integer expected by C code
if(CONFIG_MLDSA_LEVEL_44)
    set(MLD_PARAM_VAL 44)
elseif(CONFIG_MLDSA_LEVEL_65)
    set(MLD_PARAM_VAL 65)
elseif(CONFIG_MLDSA_LEVEL_87)
    set(MLD_PARAM_VAL 87)
else()
    # Default fallback
    set(MLD_PARAM_VAL 87)
endif()

# Pass the correct macro name to the compiler
zephyr_library_compile_definitions(MLD_CONFIG_PARAMETER_SET=${MLD_PARAM_VAL})