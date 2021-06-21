find_package(Catch2 REQUIRED)
include(Catch)

add_executable(
  tests
  catch_main.cpp
  container_factory_tests.cpp
  is_std_array_tests.cpp
  create_array_tests.cpp
  alternative_type_tests.cpp
  incremented_type_tests.cpp
  remove_cvref_tests.cpp
  default_dynamic_container_tests.cpp
  default_container_tests.cpp)

target_link_libraries(tests PRIVATE project_warnings project_options
                                    OnKiGenerics::OnKiGenerics Catch2::Catch2)

# automatically discover tests that are defined in catch based test files you
# can modify the unittests. TEST_PREFIX to whatever you want, or use different
# for different binaries
catch_discover_tests(
  tests
  TEST_PREFIX
  "unittests."
  EXTRA_ARGS
  -s
  --reporter=xml
  --out=tests.xml)

report_code_coverage(tests ${CMAKE_CURRENT_BINARY_DIR}/tests)
