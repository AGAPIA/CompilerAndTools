set(PROJECT_NAME Compiler)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "agapia.txt"
#    "calc3.l"
#    "calc3.output"
#    "calc3.y"
    "DISPATCHJOBS"
    "grammar.bat"
)
source_group("" FILES ${no_group_source_files})

set(Headers
	"Redefinitions.h"
    "AgapiaAIExample.h"
    "AgapiaToCCode.h"
    "ASIGNMENTNode.h"
    "BaseNode.h"
    "BufferedDataTypes.h"
#    "calc3.hpp"
    "calc3_defs.h"
    "calc3_utils.h"
    "ClassTestUse.h"
    "CModuleCode.h"
    "CodeSerializationFactory.h"
    "ExecutionCommon.h"
    "CommonTypes_Conditionals.h"
    "CommonUtils.h"
    "CompilationBlackbox.h"
    "DECLARATIONNode.h"
    "ExecutionBlackbox.h"
    "ExecutionStrategy.h"
    "ExecutionStrategy_Defines.h"
    "ExecutionStrategyConcrete_MPI.h"
    "ExecutionStrategyConcrete_Serial.h"
    "Expressions.h"
    "FOREachNode.h"
    "FORNormalNode.h"
    "GLOBALDebugParams.h"
    "IFNode.h"
    "Includes.h"
    "InputTypes.h"
    "INTERMEDIATENode.h"
    "MainInputParser.h"
    "platform.h"
    "Profiler.h"
    "ReferenceNode.h"
    "Streams.h"
    "SymbolTable.h"
    "utils.h"
    "WHILENode.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "AgapiaToCCode.cpp"
    "AgapiaToCCode_ExecutorImpl.cpp"
    "ASIGNMENTNode.cpp"
    "BaseNode.cpp"
#    "calc3.cpp"
#    "calc3.tab.c"
    "calc3_utils.cpp"
    "CModuleCode.cpp"
    "CodeSerializationFactory.cpp"
    "CommonUtils.cpp"
    "CompilationBlackbox.cpp"
    "DECLARATIONNode.cpp"
    "ExecutionBlackbox.cpp"
    "ExecutionStrategy.cpp"
    "ExecutionStrategyConcrete_MPI.cpp"
    "ExecutionStrategyConcrete_Serial.cpp"
    "Expression.cpp"
    "FOREachNode.cpp"
    "FORNormal.cpp"
    "IFNode.cpp"
    "InputTypes.cpp"
    "INTERMEDIATENode.cpp"
#    "interpretor.c"
#    "lex.yy.c"
    "main.cpp"
    "MainInputParser.cpp"
    "Parser_LexWrapper.c"
    "Parser_YaccWrapper.cpp"
    "Profiler.cpp"
    "ReferenceNode.cpp"
    "Streams.cpp"
    "SymbolTable.cpp"
    "WHILENode.cpp"
#    "y.tab.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${no_group_source_files}
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

add_precompiled_header(${PROJECT_NAME} "stdafx.h" ".")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE Compiler)

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
            "_DEBUG"
        ">"
        "$<$<CONFIG:DistributedRelease>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:IterativeDebug>:"
            "_DEBUG;"
            "EXECUTION_STRATEGY_ITERATIVE"
        ">"
        "$<$<CONFIG:IterativeRelease>:"
            "NDEBUG;"
            "EXECUTION_STRATEGY_ITERATIVE"
        ">"
        "WIN32;"
        "_CONSOLE;"
        "_CRT_SECURE_NO_WARNINGS;"
        "CRT_SECURE_NO_WARNINGS;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:DistributedDebug>:"
            "_DEBUG"
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
        "_CONSOLE;"
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
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DistributedDebug>:
                /Od
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
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DistributedDebug>:
                /INCREMENTAL
            >
            $<$<CONFIG:DistributedRelease>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:IterativeDebug>:
                /INCREMENTAL
            >
            $<$<CONFIG:IterativeRelease>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DistributedDebug>:
                /INCREMENTAL
            >
            $<$<CONFIG:DistributedRelease>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:IterativeDebug>:
                /INCREMENTAL
            >
            $<$<CONFIG:IterativeRelease>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
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
        "odbccp32;"
        "$(SolutionDir)$(Configuration)\ScedulersDistributed;"
        "msmpi"
    )
# elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
#     set(ADDITIONAL_LIBRARY_DEPENDENCIES
#         "${SolutionDir}${Configuration}/ScedulersDistributed;"
#     )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")
find_package(MPI REQUIRED)
message(STATUS "Run: ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} ${MPIEXEC_MAX_NUMPROCS} ${MPIEXEC_PREFLAGS} EXECUTABLE ${MPIEXEC_POSTFLAGS} ARGS")
target_link_libraries(${PROJECT_NAME} PUBLIC MPI::MPI_CXX)
# option(REDEFINITIONS "Cross-platform symbol redefinitions" ON)
# if(REDEFINITIONS)
#     target_compile_definitions(${PROJECT_NAME} PUBLIC REDEF=1)
# endif()

# Or optional platform detection
if(UNIX) 
    target_compile_definitions(${PROJECT_NAME} PUBLIC REDEF=1)
endif()
