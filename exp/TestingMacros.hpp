// #ifndef TESTINGMACROS_HPP
// #define TESTINGMACROS_HPP

// #define EXPECT_ITERABLE_BASE( PREDICATE, REFTYPE, TARTYPE, ref, target) \
//     { \
//     const REFTYPE& ref_(ref); \
//     const TARTYPE& target_(target); \
//     REFTYPE::const_iterator refIter = ref_.begin(); \
//     TARTYPE::const_iterator tarIter = target_.begin(); \
//     unsigned int i = 0; \
//     while(refIter != ref_.end()) { \
//         if ( tarIter == target_.end() ) { \
//             ADD_FAILURE() << #target " has a smaller length than " #ref ; \
//             break; \
//         } \
//         PREDICATE(* refIter, * tarIter) \
//             << "Containers " #ref  " (refIter) and " #target " (tarIter)" \
//                " differ at index " << i; \
//         ++refIter; ++tarIter; ++i; \
//     } \
//     EXPECT_TRUE( tarIter == target_.end() ) \
//         << #ref " has a smaller length than " #target ; \
//     }

// // Check that all elements of two same-type containers are equal
// #define EXPECT_ITERABLE_EQ( TYPE, ref, target) \
//     EXPECT_ITERABLE_BASE( EXPECT_EQ, TYPE, TYPE, ref, target )

// #endif
