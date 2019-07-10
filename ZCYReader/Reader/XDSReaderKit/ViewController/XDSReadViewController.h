//
//  XDSReadViewController.h
//  XDSReader
//
//  Created by dusheng.xu on 07/07/2017.
//  Copyright © 2017 macos. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface XDSReadViewController : UIViewController

@property (nonatomic, strong) XDSReadView *readView;

@property (nonatomic, assign) NSInteger chapterNum;//
@property (nonatomic, assign) NSInteger pageNum;
@property (nonatomic, copy) NSString *pageUrl;


/*
 * 通过章节号与章节内的页码进行初始化
 */
- (instancetype)initWithChapterNumber:(NSInteger)chapterNum pageNumber:(NSInteger)pageNum;


///*
// * 通过url进行初始化，主要是epub目录有可能使用页码进行跳转
// */
//- (instancetype)initWithPageUrl:(NSString *)pageUrl;

@end
