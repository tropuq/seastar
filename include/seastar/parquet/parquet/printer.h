// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef PARQUET_FILE_PRINTER_H
#define PARQUET_FILE_PRINTER_H

#include <iosfwd>
#include <list>

#include <seastar/parquet/parquet/platform.h>

namespace parquet {

class ParquetFileReader;

class PARQUET_EXPORT ParquetFilePrinter {
 private:
  ParquetFileReader* fileReader;

 public:
  explicit ParquetFilePrinter(ParquetFileReader* reader) : fileReader(reader) {}
  ~ParquetFilePrinter() {}

  void DebugPrint(std::ostream& stream, std::list<int> selected_columns,
      bool print_values = false, bool format_dump = false,
      bool print_key_value_metadata = false,
      const char* filename = "No Name");

  void JSONPrint(std::ostream& stream, std::list<int> selected_columns,
      const char* filename = "No Name");
};

namespace seastarized {

class ParquetFileReader;

class PARQUET_EXPORT ParquetFilePrinter {
 private:
  ParquetFileReader* fileReader;

 public:
  explicit ParquetFilePrinter(ParquetFileReader* reader) : fileReader(reader) {}
  ~ParquetFilePrinter() {}

  void DebugPrint(std::ostream& stream, std::list<int> selected_columns,
      bool print_values = false, bool format_dump = false,
      bool print_key_value_metadata = false,
      const char* filename = "No Name");

  void JSONPrint(std::ostream& stream, std::list<int> selected_columns,
      const char* filename = "No Name");
};

} // namespace seastarized

}  // namespace parquet

#endif  // PARQUET_FILE_PRINTER_H
