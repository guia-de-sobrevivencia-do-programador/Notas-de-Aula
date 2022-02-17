#!/bin/bash

select EXEC in `find -type f -executable`
do
	$EXEC
done
