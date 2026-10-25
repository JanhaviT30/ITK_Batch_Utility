# Teamcenter ITK Batch Utility Codes

A collection of learning examples and documentation for
standalone batch utilities using C/C++ and Siemens Teamcenter ITK.

## Overview

This repository explores batch processing, legacy data migration,
file handling, Teamcenter object operations, and error handling.

## Topics Covered

- C/C++ programming for batch utilities
- CSV and text-file processing
- Teamcenter ITK session initialization
- Item and Item Revision creation concepts
- Dataset and named-reference handling
- Property and relationship management
- Duplicate record validation
- Error logging and failure recovery

## Repository Structure

| Folder | Purpose |
|---|---|
| `01-cpp-fundamentals/` | C/C++ fundamentals |
| `02-file-processing/` | CSV and file-handling examples |
| `03-teamcenter-itk/` | ITK concepts and examples |
| `04-documentation/` | Design notes and troubleshooting |

## Design Principles

- Validate input before processing.
- Check API return codes and report failures.
- Log errors with enough context to troubleshoot.
- Continue processing independent records after an individual failure,
  where safe and appropriate.
- Document prerequisites and execution steps.

## Technologies

- C / C++
- Siemens Teamcenter ITK
- GitHub

## Disclaimer

This is a personal learning and portfolio repository.
All published examples and documentation must be original
or appropriately licensed. No confidential company or client
code, data, credentials, or proprietary configuration is included.
