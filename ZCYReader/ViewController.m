//
//  ViewController.m
//  ZCYReader
//
//  Created by zhao on 2019/7/2.
//  Copyright © 2019 zhao. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *arrCellData;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.arrCellData = @[@{@"name": @"每天懂一点好玩心理学", @"extensition": @"epub"},
                         @{@"name": @"妖神记", @"extensition": @"txt"}];
    
    [self.view addSubview:self.tableView];
}

#pragma mark - UITableViewDatasource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.arrCellData.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cell"];
    }
    
    NSDictionary *dicCell = self.arrCellData[indexPath.row];
    cell.textLabel.text = [NSString stringWithFormat:@"%@.%@", dicCell[@"name"], dicCell[@"extensition"]];
    return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSDictionary *dicCell = self.arrCellData[indexPath.row];
    NSURL *fileURL = [[NSBundle mainBundle] URLForResource:dicCell[@"name"] withExtension:dicCell[@"extensition"]];
    [self readBookWithFileURL:fileURL];
}

- (void)readBookWithFileURL:(NSURL *)fileURL
{
    if (fileURL == nil) { return; }
    
    // 开始阅读
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        XDSBookModel *bookModel = [XDSBookModel getLocalModelWithURL:fileURL];
        dispatch_async(dispatch_get_main_queue(), ^{
            XDSReadPageViewController *readVC = [[XDSReadPageViewController alloc] init];
            [[XDSReadManager sharedManager] setResourceURL:fileURL];
            [[XDSReadManager sharedManager] setBookModel:bookModel];
            [[XDSReadManager sharedManager] setRmDelegate:readVC];
            [self presentViewController:readVC animated:YES completion:nil];
        });
    });
}

#pragma mark - setter

- (UITableView *)tableView
{
    if (_tableView == nil) {
        _tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        
        _tableView.estimatedRowHeight = 44;
        _tableView.rowHeight = UITableViewAutomaticDimension;
    }
    return _tableView;
}

@end
