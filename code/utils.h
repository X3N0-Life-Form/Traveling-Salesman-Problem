/* 
 * File:   utils.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 14:25
 */

#ifndef UTILS_H
#define	UTILS_H

#define ARRAY_COPY(target, source, length) for (int i = 0; i < length; i++) {target[i] = source[i];}
#define SWAP(target, i, j) auto c = target[i]; target[i]=target[j]; target[j]=c;

#endif	/* UTILS_H */

