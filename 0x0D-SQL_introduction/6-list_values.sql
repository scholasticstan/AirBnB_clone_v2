#!/bin/bash
-- Script to list all rows of the table first_table from the database hbtn_0c_0

-- Get the database name from the command line argument
database=$1

-- Run the SQL query using the mysql command
echo "SELECT * FROM first_table;" | mysql -h localhost -u root -p $database
