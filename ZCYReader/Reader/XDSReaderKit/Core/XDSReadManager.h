//
//  XDSReadManager.h
//  XDSReader
//
//  Created by dusheng.xu on 2017/6/16.
//  Copyright © 2017年 macos. All rights reserved.
//

#import <Foundation/Foundation.h>

#define CURRENT_BOOK_MODEL [XDSReadManager sharedManager].bookModel // 图书详情
#define CURRENT_RECORD [XDSReadManager sharedManager].bookModel.record // 阅读进度

@protocol XDSReadManagerDelegate;

@interface XDSReadManager : NSObject

/** 资源文件地址 */
@property (nonatomic, strong) NSURL *resourceURL;
/** 图书模型 */
@property (nonatomic, strong) XDSBookModel *bookModel;
/** 代理 */
@property (nonatomic, weak) id<XDSReadManagerDelegate> rmDelegate;

+ (XDSReadManager *)sharedManager;
+ (CGRect)readViewBounds;

/** 获取对于章节页码的radViewController */
- (XDSReadViewController *)readViewWithChapter:(NSInteger *)chapter
                                          page:(NSInteger *)page
                                       pageUrl:(NSString *)pageUrl;

/** 跳转到指定章节（上一章，下一章，slider，目录） */
- (void)readViewJumpToChapter:(NSInteger)chapter page:(NSInteger)page;
/** 跳转到指定笔记，因为是笔记是基于位置查找的，使用page查找可能出错 */
- (void)readViewJumpToNote:(XDSNoteModel *)note;
/** 跳转到指定书签，因为是书签是基于位置查找的，使用page查找可能出错 */
- (void)readViewJumpToMark:(XDSMarkModel *)mark;
/** 设置字体大小; */
- (void)configReadFontSize:(BOOL)plus;
/** 设置字体; */
- (void)configReadFontName:(NSString *)fontName;

/** 设置阅读背景 */
- (void)configReadTheme:(UIColor *)theme;
/** 更新阅读记录 */
- (void)updateReadModelWithChapter:(NSInteger)chapter page:(NSInteger)page;
/** 关闭阅读器 */
- (void)closeReadView;
/** 添加或删除书签 */
- (void)addBookMark;
/** 添加笔记 */
- (void)addNoteModel:(XDSNoteModel *)noteModel;

@end

@protocol XDSReadManagerDelegate <NSObject>
@optional

/** 点击关闭按钮 */
- (void)readViewDidClickCloseButton;
/** 字体改变 */
- (void)readViewFontDidChanged;
/** 主题改变 */
- (void)readViewThemeDidChanged;
/** 翻页效果改变 */
- (void)readViewEffectDidChanged;
/** 添加笔记 */
- (void)readViewDidAddNoteSuccess;
/** 跳转到章节 */
- (void)readViewJumpToChapter:(NSInteger)chapter page:(NSInteger)page;
/** 更新阅读进度 */
- (void)readViewDidUpdateReadRecord;

@end
