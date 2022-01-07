	//MODULE hash
	//  IMPLICIT NONE
	//  PRIVATE
	// 
	//  PUBLIC :: hash_init
	//  PUBLIC :: hash_push
	//  PUBLIC :: hash_get
	//  PUBLIC :: hash_set
	//  PUBLIC :: hash_print
	// 
	//  INTEGER,               PARAMETER   :: CharLength = 128
	//  CHARACTER(CharLength), ALLOCATABLE :: keys(:)
	//  REAL,                  ALLOCATABLE :: values(:)
	//  INTEGER                            :: hash_index
	// 
	//CONTAINS
	// 
	//  SUBROUTINE hash_init(no_items)
	//    INTEGER, INTENT(in)  :: no_items
	//    INTEGER              :: status
	//    ALLOCATE(keys(no_items), stat=status)
	//    ALLOCATE(values(no_items), stat=status)
	//    hash_index = 0 
	//  END SUBROUTINE hash_init
	// 
	//  SUBROUTINE hash_push(key, value)
	//    CHARACTER(*), INTENT(IN)     :: key
	//    REAL        , INTENT(IN)     :: value
	//    hash_index = hash_index + 1
	//    IF(hash_index > Size(keys, 1)) CALL print_error("Error: Hash table is already full")
	//    keys(hash_index) = key
	//    values(hash_index) = value
	//  END SUBROUTINE hash_push
	// 
	//  SUBROUTINE hash_set(key, value)
	//    CHARACTER(*), INTENT(IN)     :: key
	//    REAL        , INTENT(IN)     :: value
	//    INTEGER                      :: local_index
	//    LOGICAL                      :: found
	//    found = .FALSE. 
	//    IF(hash_index &lt; Size(keys, 1)) CALL print_error("Error: the hashtable is not yet full") 
	//    DO local_index = 1,Size(keys,1)
	//      IF(TRIM(keys(local_index)) == TRIM(key)) THEN 
	//	values(local_index) = value
	//	found = .TRUE.
	//      ENDIF
	//    ENDDO 
	//    IF(.NOT.found) CALL print_error("Unknown key")
	//  END SUBROUTINE hash_set
	// 
	//  SUBROUTINE hash_get(key, value)
	//    CHARACTER(*), INTENT(IN)     :: key
	//    REAL        , INTENT(OUT)    :: value
	//    INTEGER                      :: local_index
	//    LOGICAL                      :: found
	//    found = .FALSE. 
	//    IF(hash_index &lt; Size(keys, 1)) CALL print_error("Error: the hashtable is not yet full") 
	//    DO local_index = 1,Size(keys,1)
	//      IF(TRIM(keys(local_index)) == TRIM(key)) THEN 
	//	value = values(local_index)
	//	found = .TRUE.
	//      ENDIF
	//    ENDDO 
	//    IF(.NOT.found) CALL print_error("Unknown key")
	//  END SUBROUTINE hash_get
	// 
	//  SUBROUTINE hash_print
	//    INTEGER  :: local_index 
	//    PRINT*, "Contents of the hashtable:"
	//    DO local_index = 1,Size(keys,1)
	//      PRINT*, TRIM(keys(local_index)), " = ", values(local_index)
	//    ENDDO
	//  END SUBROUTINE hash_print
	// 
	//  SUBROUTINE print_error(text)
	//    CHARACTER(*) :: text
	//    PRINT*, text
	//    STOP
	//  END SUBROUTINE print_error
	//END MODULE hash



	//PROGRAM hash_test
	//  use hash
	//  REAL :: res = 0.0
	// 
	//  CALL hash_init(3)
	// 
	//  CALL hash_push("one", 1.0)
	//  CALL hash_push("two", 2.0)
	//  CALL hash_push("three", 3.0)
	// 
	//  CALL hash_print
	//  CALL hash_get("one", res)
	//  PRINT*, res
	//  CALL hash_get("two", res)
	//  PRINT*, res
	// 
	//  CALL hash_set("one", 60.0)
	// 
	//  CALL hash_print
	//  CALL hash_get("one", res)
	//  PRINT*, res
	//END PROGRAM hash_test
