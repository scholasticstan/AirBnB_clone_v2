#!/bin/bash
-- This script list all data in a table

database=$1

mysql -uroot -p -e "USE $database; SELECT * FROM first_table;"

