configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.rc
  @ONLY)

add_library(JCJIndex SHARED
    ${CMAKE_CURRENT_BINARY_DIR}/version.rc
    TestPluginTCale.cpp
    StdAfx.h
    StdAfx.cpp
    StdFunction.cpp
    StdFunction.h
    jcj_utils.h
    jcj_utils.cpp
    jcj_index.cc
    jcj_index.h
    jdxj_up.cc
    jdxj_up.h
    jdxj_down.cc
    # jdxj_down.h
    zdld.h
    zdld.cc
    dkxh.cc
    dkxh.h
    qstd.cc
    zldn.h
    zldn.cc
)

if (JCJ_INDEX_OUTPUT_TDX_DLL)
    target_sources(JCJIndex
        PRIVATE
            tdx_register.h
            tdx_register.cc
    )
else()
    target_sources(JCJIndex
        PRIVATE
            jcj_register.h
            jcj_register.cc
    )
endif()

# add_custom_command(TARGET JCJIndex POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         $<TARGET_FILE:JCJIndex>
#         "c:/Users/dz/JCE/dlls"
# )

# 定义自定义命令
# add_custom_command(TARGET JCJIndex POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:test>/dlls"
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         $<TARGET_FILE:JCJIndex>
#         $<TARGET_FILE_DIR:test>/dlls
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         ${CMAKE_SOURCE_DIR}/configs/dlls.ini
#         $<TARGET_FILE_DIR:test>/dlls
# )


add_library(TestDLL SHARED
    test_dll.cc
    test_register.cc
    TestPluginTCale.cpp
    StdAfx.h
    StdAfx.cpp
    StdFunction.cpp
    StdFunction.h
    jcj_utils.h
    jcj_utils.cpp
    jcj_index.cc
    jcj_index.h
    jdxj_up.cc
    jdxj_up.h
    jdxj_down.cc
    # jdxj_down.h
    zdld.h
    zdld.cc
    dkxh.cc
    dkxh.h
    qstd.cc
    zldn.h
    zldn.cc
)

if (JCJ_INDEX_TEST)
add_custom_command(TARGET TestDLL POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:test>/dlls"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:TestDLL>
        $<TARGET_FILE_DIR:test>/dlls
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/configs/dlls.ini
        $<TARGET_FILE_DIR:test>/dlls
)
endif(JCJ_INDEX_TEST)


##############################################
# Installation instructions

include(GNUInstallDirs)
install(TARGETS JCJIndex
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

