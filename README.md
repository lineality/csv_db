# csv_db

# About The Project
csv_db or ".csv (file) Database" is the overall name for a proposed, open source, solution to various database, dataframe, data scale, data format issues. For example, a person (or a group) should be able to take any .csv file(s) and quickly and easily perform any basic:
1. data exploration (Exploratory Data Analysis)
2. database function (SQL queries, joins etc)
3. dataframe operations (as in Pandas df[]. or R operations)
4. gracefully handling scale issues on all levels
5. data lake, data warehouse, No-SQL operations involving unusual datatypes, media files,etc. 


## Modular and Clear:

The basic overall structure (c version): 
csv_db will be run by c executable files that will call each-other. These can either be used in a reasonably user friendly way directly in a command line interface terminal (often the best, or simply required, as time as shown) or these can be called by some other TUI, GUI, API, etc.
Files will be transparently stored in a data directory, with the main .csv files backed-up and unaltered.

## Memory and Speed

csv_db is designed to be very RAM thin, likely able to run in a very minimal system, yet (ideally) still able to process large files. This system is not meant to be the fastest or the most hard-drive-memory conserving. "I ran out of RAM" is something data scientists tell each-other every few minutes. "I ran out of hard drive space" is something I don't think I have ever heard a data scientist say since data science became a thing in ~2015. 


## Metafiles & Distributed .csv format

.csv files alone do not contain all the information that a dataframe contains (or all the abilities of a SQL databse) yet the simple portability and 'transparency' of a .csv file that simply is what it is, a file on your system (as opposed to a database or dataframe that lives...somewhere mysterious.) 




## Notes:

Modular 

# Easy api_endpoint (flast/fast_api) server setup for csv_db


## Tools for examining, linting, compiling, c source code (locally, python notebook, cloud, etc.)
- .ipynb files
- demo.csv
- gcc
- cpplint


# Individual .csv Tools:
- shape.exe (like df.shape() in python pandas)
- head.exe (like df.head() in python pandas)
