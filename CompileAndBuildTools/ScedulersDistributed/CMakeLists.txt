set(PROJECT_NAME ScedulersDistributed)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "ReadMe.txt"
)
source_group("" FILES ${no_group_source_files})

set(Source_Files
    "SchedulerCODef.h"
    "SchedulerCODef_Master.cpp"
    "SchedulerCODef_Worker.cpp"
    "SchedulerUtils.h"
    "SimulationParams.h"
    "stdafx.cpp"
    "stdafx.h"
    "targetver.h"
#    "TestScheduler.cpp"
#    "TestScheduler.h"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${no_group_source_files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE ScedulersDistributed)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_DISTRIBUTEDRELEASE "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_ITERATIVERELEASE   "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_DISTRIBUTEDDEBUG   "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_DISTRIBUTEDRELEASE "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_ITERATIVERELEASE   "TRUE"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:DistributedDebug>:"
            "_DEBUG;"
            "_CRT_SECURE_NO_WARNINGS;"
            "USE_SCHEDULER_LOGS"
        ">"
        "$<$<CONFIG:DistributedRelease>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:IterativeDebug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:IterativeRelease>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_LIB;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:DistributedDebug>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:DistributedRelease>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:IterativeDebug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:IterativeRelease>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_LIB;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DistributedDebug>:
                /Od
            >
            $<$<CONFIG:DistributedRelease>:
                /Ox;
                /Oi;
                /Gy
            >
            $<$<CONFIG:IterativeDebug>:
                /Od
            >
            $<$<CONFIG:IterativeRelease>:
                /O2;
                /Oi;
                /Gy
            >
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DistributedDebug>:
                /O2;
                /Oi;
                /Gy
            >
            $<$<CONFIG:DistributedRelease>:
                /O2;
                /Oi;
                /Gy
            >
            $<$<CONFIG:IterativeDebug>:
                /Od
            >
            $<$<CONFIG:IterativeRelease>:
                /O2;
                /Oi;
                /Gy
            >
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:DistributedRelease>:"
                "/Ox"
            ">"
        )
    endif()
    source_file_compile_options(TestScheduler.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DistributedDebug>:
                /SUBSYSTEM:WINDOWS
            >
            $<$<CONFIG:DistributedRelease>:
                /SUBSYSTEM:CONSOLE;
                /OPT:REF;
                /OPT:ICF
            >
            $<$<CONFIG:IterativeDebug>:
                /SUBSYSTEM:WINDOWS
            >
            $<$<CONFIG:IterativeRelease>:
                /SUBSYSTEM:WINDOWS;
                /OPT:REF;
                /OPT:ICF
            >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DistributedDebug>:
                /OPT:REF;
                /OPT:ICF
            >
            $<$<CONFIG:DistributedRelease>:
                /OPT:REF;
                /OPT:ICF
            >
            $<$<CONFIG:IterativeRelease>:
                /OPT:REF;
                /OPT:ICF
            >
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:DistributedRelease>:"
            # "msmpi;"
            "kernel32;"
            "user32;"
            "gdi32;"
            "winspool;"
            "comdlg32;"
            "advapi32;"
            "shell32;"
            "ole32;"
            "oleaut32;"
            "uuid;"
            "odbc32;"
            "odbccp32"
        ">"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")
target_link_libraries(${PROJECT_NAME} PUBLIC MPI::MPI_CXX)
